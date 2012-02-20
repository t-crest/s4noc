library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;

use work.noc_types.all;

entity serdes is
  
  generic (
    TILE_WIDTH : integer := 16;
    RATIO_CLK  : integer := 2);

  port (
    fast_clk     : in  std_logic;
    slow_clk     : in  std_logic;
    reset        : in  std_logic;
    serial_in    : in  std_logic_vector((TILE_WIDTH/RATIO_CLK)-1 downto 0);
    parallel_in  : in  std_logic_vector(TILE_WIDTH-1 downto 0);
    serial_out   : out std_logic_vector((TILE_WIDTH/RATIO_CLK)-1 downto 0);
    parallel_out : out std_logic_vector(TILE_WIDTH-1 downto 0));
end serdes;

architecture behave of serdes is
  constant SERIAL_REG_WIDTH : integer := TILE_WIDTH/RATIO_CLK;
  type     registers is array (1 to RATIO_CLK-1) of std_logic_vector((SERIAL_REG_WIDTH)-1 downto 0);

  -- SIPO signals

  signal sipo_regs : registers;

  -- PISO signals

  signal piso_regs      : registers;
  signal next_piso_regs : registers;
  signal piso_phase     : std_logic;

  -- Constants

  constant ZERO_PHASE : std_logic                                     := '0';
  constant ONE_PHASE  : std_logic                                     := '1';
  constant ZERO_REG   : std_logic_vector(SERIAL_REG_WIDTH-1 downto 0) := std_logic_vector(to_unsigned(0, SERIAL_REG_WIDTH));
  
begin  -- behave
-------------------------------------------------------------------------------
-- SIPO (Serial In Parallel Out)
-------------------------------------------------------------------------------

  sipo_shregs : process (fast_clk, reset)
  begin  -- process shregs
    if reset = '1' then                 -- asynchronous reset (active high)
      for i in 1 to RATIO_CLK-1 loop
        sipo_regs(i) <= ZERO_REG;
      end loop;  -- i
    elsif rising_edge(fast_clk) then    -- rising clock edge
      for i in 1 to RATIO_CLK-1 loop
        if i = 1 then
          sipo_regs(i) <= serial_in;
        else
          sipo_regs(i) <= sipo_regs(i-1);
        end if;
      end loop;  -- i
    end if;
  end process sipo_shregs;

  parallel_out((SERIAL_REG_WIDTH)-1 downto 0) <= serial_in;
  i : for i in 1 to RATIO_CLK-1 generate
    parallel_out((SERIAL_REG_WIDTH*(i+1))-1 downto SERIAL_REG_WIDTH*i) <= sipo_regs(i);
  end generate i;

-------------------------------------------------------------------------------
-- PISO (Parallel In Serial Out)
-------------------------------------------------------------------------------

  border : if RATIO_CLK > 1 generate
    next_piso_regs(1) <= parallel_in((SERIAL_REG_WIDTH)-1 downto 0);
    serial_out        <= parallel_in(TILE_WIDTH-1 downto TILE_WIDTH-SERIAL_REG_WIDTH) when piso_phase = ZERO_PHASE else piso_regs(RATIO_CLK-1);

    ii : if RATIO_CLK > 2 generate
      i : for i in 2 to RATIO_CLK-1 generate
        next_piso_regs(i) <= parallel_in((SERIAL_REG_WIDTH*i)-1 downto SERIAL_REG_WIDTH*(i-1)) when piso_phase = ZERO_PHASE else piso_regs(i-1);
      end generate i;
    end generate ii;

    piso_shregs : process (fast_clk, slow_clk, reset)
    begin  -- process piso_shregs
      if reset = '1' then               -- asynchronous reset (active high)
        for i in 1 to RATIO_CLK-1 loop
          piso_regs(i) <= ZERO_REG;
        end loop;  -- i
      elsif rising_edge(fast_clk) then  -- rising clock edge
        piso_regs <= next_piso_regs;
      end if;
    end process piso_shregs;
  end generate border;

  border1 : if RATIO_CLK = 1 generate
    serial_out <= parallel_in;
  end generate border1;

-------------------------------------------------------------------------------
-- Phase generation for the PISO (Only working for RATIO_CLK = 2, should be generalized)
-------------------------------------------------------------------------------

  piso_phase <= not slow_clk;
  
end behave;
