library ieee;
use ieee.std_logic_1164.all;

use work.leros_types.all;
use work.noc_types.all;

entity tile is
  generic (
    UART     : boolean := false);
  port (
    router_clk    : in std_logic;
    processor_clk : in std_logic;
    reset         : in std_logic;

    north_in : in network_link_forward;
    south_in : in network_link_forward;
    east_in  : in network_link_forward;
    west_in  : in network_link_forward;

    north_out : out network_link_forward;
    south_out : out network_link_forward;
    east_out  : out network_link_forward;
    west_out  : out network_link_forward;

    ser_txd : out std_logic;
    ser_rxd : in  std_logic
    );

end tile;

architecture struct of tile is
  signal processor_out : io_out_type;
  signal processor_in  : io_in_type;

  signal local_in  : network_link_forward;
  signal tile_tx_b : network_link_backward;
  signal local_out : network_link_forward;
  
begin  -- struct

  leros : entity work.leros
    port map (
      clk   => processor_clk,
      reset => reset,
      ioout => processor_out,
      ioin  => processor_in);


  gen_ua : if UART generate
    ua : entity work.uart
      generic map (
        clk_freq  => 100000000,
        baud_rate => 115200,
        txf_depth => 1,
        rxf_depth => 1)
      port map (
        clk     => processor_clk,
        reset   => reset,
        address => processor_out.addr(0),
        wr_data => processor_out.wrdata,
        rd      => processor_out.rd,
        wr      => processor_out.wr,
        rd_data => processor_in.rddata,

        txd => ser_txd,
        rxd => ser_rxd);
  end generate gen_ua;

  ni : entity work.ni
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,
      tile_tx_f     => local_in,
      tile_tx_b     => tile_tx_b,
      tile_rx_f     => local_out,
      tile_rx_b     => open,
      processor_out => processor_out,
      processor_in  => processor_in);

  
  router_node : entity work.router
    port map (
      clk       => router_clk,
      reset     => reset,
      north_in  => north_in,
      south_in  => south_in,
      east_in   => east_in,
      west_in   => west_in,
      local_in  => local_in,
      north_out => north_out,
      south_out => south_out,
      east_out  => east_out,
      west_out  => west_out,
      local_out => local_out);

end struct;
