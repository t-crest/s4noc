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

    sel     : in  integer range 0 to 3;
    reg_out : out network_link_forward
    );
end entity outnode;

architecture arc of outnode is

  signal next_q : network_link_forward;

begin

  with sel select
    next_q <= in0 when 0,
    in1           when 1,
    in2           when 2,
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

