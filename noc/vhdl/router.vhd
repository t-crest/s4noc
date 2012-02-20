library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;

entity router is
  port(
    clk   : in std_logic;
    reset : in std_logic;

    north_in : in network_link_forward;
    south_in : in network_link_forward;
    east_in  : in network_link_forward;
    west_in  : in network_link_forward;
    local_in : in network_link_forward;

    north_out : out network_link_forward;
    south_out : out network_link_forward;
    east_out  : out network_link_forward;
    west_out  : out network_link_forward;
    local_out : out network_link_forward
    );
end entity router;


architecture struct of router is

  component outnode 
    port (
      clk   : in std_logic;
      reset : in std_logic;
      in0   : in network_link_forward;
      in1   : in network_link_forward;
      in2   : in network_link_forward;
      in3   : in network_link_forward;

      reg_out : out network_link_forward
      );
  end component;
  signal sel : std_logic_vector(1 downto 0);

begin

  north_output : outnode
    port map (in0     => local_in, in1 => south_in,
              in2     => east_in, in3 => west_in,
              clk     => clk, reset => reset,
              reg_out => north_out);

  south_output : outnode
    port map(in0     => north_in, in1 => local_in,
             in2     => east_in, in3 => west_in,
             clk     => clk, reset => reset,
             reg_out => south_out);


  east_output : outnode
    port map(in0     => north_in, in1 => south_in,
             in2     => local_in, in3 => west_in,
             clk     => clk, reset => reset,
             reg_out => east_out);


  west_output : outnode
    port map(in0     => north_in, in1 => south_in,
             in2     => east_in, in3 => local_in,
             clk     => clk, reset => reset,
             reg_out => west_out);


  local_output : outnode
    port map(in0     => north_in, in1 => south_in,
             in2     => east_in, in3 => west_in,
             clk     => clk, reset => reset,
             reg_out => local_out);


end architecture struct;

