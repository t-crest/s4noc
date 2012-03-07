library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;

entity outnode is
  port(
    clk   : in std_logic;
    reset : in std_logic;
    in0   : in network_link_forward;
    in1   : in network_link_forward;
    in2   : in network_link_forward;
    in3   : in network_link_forward;

    reg_out : out network_link_forward
    );
end entity outnode;

architecture arc of outnode is

  signal sel      : std_logic_vector(1 downto 0);
  signal slt_cnt  : unsigned(3 downto 0);
  signal next_slt : unsigned(3 downto 0);
  alias count     : unsigned(2 downto 0) is slt_cnt(3 downto 1);
  signal next_q   : network_link_forward;

begin

  -- counter
  slot_counter : process (clk, reset, slt_cnt) is
  begin
    if reset = '1' then
      slt_cnt <= to_unsigned(0, 4);
    elsif rising_edge(clk) then
      slt_cnt <= next_slt;
    end if;
    next_slt <= slt_cnt + 1;
  end process slot_counter;

  -- schedule table
  sel <= "00" when count = 0 or count = 4 else  --north
         "01" when count = 1 or count = 5 else  --south
         "10" when count = 2 or count = 7 else  --east
         "11";                          --west


--      -- mux 4-to-1
--      CL : process (sel, in0, in1, in2, in3) is
--      begin
--              if sel = "00" then
--                      next_state <= in0;
--              elsif sel = "01" then
--                      next_state <= in1;
--              elsif sel = "10" then
--                      next_state <= in2;
--              else
--                      next_state <= in3;
--              end if;
--      end process CL;

  with sel select
    next_q <= in0 when "00",
    in1           when "01",
    in2           when "10",
    in3           when others;

  -- output assignment
  Reg : process (clk, reset) is
  begin
    if reset = '1' then
      reg_out.data       <= (others => '0');
      reg_out.data_valid <= '0';
    elsif rising_edge(clk) then
      reg_out <= next_q;
    end if;
  end process Reg;

end architecture arc;

