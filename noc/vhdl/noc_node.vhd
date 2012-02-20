library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.leros_types.all;
use work.noc_types.all;


entity noc_node is
  generic (WIDTH    : natural;
           PERIOD_P : natural);
  port (p_clk : in std_logic;
        n_clk : in std_logic;
        reset : in std_logic;

        north_in : in network_link_forward;
        south_in : in network_link_forward;
        east_in  : in network_link_forward;
        west_in  : in network_link_forward;

        north_out : out network_link_forward;
        south_out : out network_link_forward;
        east_out  : out network_link_forward;
        west_out  : out network_link_forward

        );
end entity noc_node;

architecture struct of noc_node is
  component router
    generic (WIDTH    : natural;
             PERIOD_P : natural);
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
  end component;
  component leros
    port (
      clk   : in  std_logic;
      reset : in  std_logic;
      ioout : out io_out_type;
      ioin  : in  io_in_type
      );
  end component;
  signal noc_in  : network_link_forward;
  signal noc_out : network_link_forward;
  signal noc_out_b : network_link_backward;
  signal p_out   : io_out_type;
  signal p_in    : io_in_type;

begin

  processor_node : leros
    port map (clk   => p_clk, reset => reset,
              ioout => p_out,
              ioin  => p_in
              );

  network_interface : entity work.ni
--    generic map (
--      stable_length => stable_length)
    port map (router_clk    => n_clk,
              processor_clk => p_clk,
              reset         => reset,
              tile_tx_f   => noc_out,
              tile_tx_b   => noc_out_b,
              tile_rx_f   => noc_in,
              tile_rx_b   => open,
              processor_out => p_out,
              processor_in  => p_in
              );

  router_node : router
    generic map (WIDTH    => WIDTH,
                 PERIOD_P => PERIOD_P)
    port map (clk       => n_clk, reset => reset,
              north_in  => north_in,
              south_in  => south_in,
              east_in   => east_in,
              west_in   => west_in,
              local_in  => noc_in,
              north_out => north_out,
              south_out => south_out,
              east_out  => east_out,
              west_out  => west_out,
              local_out => noc_out
              );

end architecture struct;
