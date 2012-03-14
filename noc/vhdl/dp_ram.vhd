-------------------------------------------------------------------------
--
-- Filename: dp_ram.vhd
-- =========
--
-- Short Description:
-- ==================
--   Dual port ram with two writing ports.
--
-- Description:
-- ============
--   Implementation of a dual port ram with two writing ports.
--   Based on the ram code described in the Xilinx XST Manual.
--
--   Both ports are using the same clock!
--   The memory uses low active control signals. The following
--   combinations are possible:
--
--    nwrx | nscx | Description
--   ----------------------------
--      0  |   0  | Write access
--      1  |   0  | Read access
--      X  |   1  | Inactive
--
--   The address and data bus width can be specified using
--   the generic map. The default is eight bit data bus and
--   eight bit address bus.
--
-- Verification:
-- =============
--   Simulated using ISE Webpack 8.2.03i running on Ubuntu Linux 6.10.
--   Synthesized using ISE Webpack 8.2.03i running on Ubuntu Linux 6.10.
--
-------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity dp_ram is
  generic
  (
    DATA_WIDTH : integer := 8;
    ADDR_WIDTH : integer := 8
  );
  port
  (
    clk : in std_logic;
    addr1 : in std_logic_vector(ADDR_WIDTH - 1 downto 0);
    data_w1 : in std_logic_vector(DATA_WIDTH - 1 downto 0);
    data_r1 : out std_logic_vector(DATA_WIDTH - 1 downto 0);
    nwr1 : in std_logic;
    ncs1 : in std_logic;
    addr2 : in std_logic_vector(ADDR_WIDTH - 1 downto 0);
    data_w2 : in std_logic_vector(DATA_WIDTH - 1 downto 0);
    data_r2 : out std_logic_vector(DATA_WIDTH - 1 downto 0);
    nwr2 : in std_logic;
    ncs2 : in std_logic
  );
end dp_ram;

architecture beh of dp_ram is
  subtype ram_entry is std_logic_vector(DATA_WIDTH - 1 downto 0);
  type ram_type is array(0 to (2 ** ADDR_WIDTH) - 1) of ram_entry;
  shared variable ram : ram_type;
begin
  process(clk)
  begin
    if rising_edge(clk) then
      if ncs1 = '0' then
        if nwr1 = '0' then
          ram(to_integer(unsigned(addr1))) := data_w1;
        else
          data_r1 <= ram(to_integer(unsigned(addr1)));
        end if;
      end if;
    end if;
  end process;

  process(clk)
  begin
    if rising_edge(clk) then
      if ncs2 = '0' then
        if nwr2 = '0' then
          ram(to_integer(unsigned(addr2))) := data_w2;
        else
          data_r2 <= ram(to_integer(unsigned(addr2)));
        end if;
      end if;
    end if;
  end process;
end beh;