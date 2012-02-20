library ieee;
use ieee.std_logic_1164.all;

library work;
use work.noc_types.all;
use work.leros_types.all;

entity tb_NI is

end tb_NI;

architecture struct of tb_NI is
  constant stable_length          : natural := 8;
  constant router_clk_period      : time    := 5 ns;
  signal   router_clk             : std_logic;
  signal   tile_clk             : std_logic;
  signal   reset                  : std_logic;
  signal   router_f_1, router_f_2 : network_link_forward;
  signal   router_b_1, router_b_2 : network_link_backward;
  signal   tile_in_1, tile_in_2   : io_in_type;
  signal   tile_out_1, tile_out_2 : io_out_type;
  
begin  -- struct

  ni_1 : entity work.ni
    generic map (
      stable_length => stable_length)
    port map (
      router_clk  => router_clk,
      tile_clk    => tile_clk,
      reset       => reset,
      router_tx_f => router_f_1,
      router_tx_b => router_b_1,
      router_rx_f => router_f_2,
      router_rx_b => router_b_2,
      tile_out    => tile_out_1,
      tile_in     => tile_in_1);

  
  leros_1 : entity work.leros
    port map (
      clk   => tile_clk,
      reset => reset,
      ioout => tile_out_1,
      ioin  => tile_in_1);

  
  ni_2 : entity work.ni
    generic map (
      stable_length => stable_length)
    port map (
      router_clk  => router_clk,
      tile_clk    => tile_clk,
      reset       => reset,
      router_tx_f => router_f_2,
      router_tx_b => router_b_2,
      router_rx_f => router_f_1,
      router_rx_b => router_b_1,
      tile_out    => tile_out_2,
      tile_in     => tile_in_2);


  leros_2 : entity work.leros
    port map (
      clk   => tile_clk,
      reset => reset,
      ioout => tile_out_2,
      ioin  => tile_in_2);

  router_clock_gen : process is
  begin  -- process clock_gen
    router_clk <= '0' after router_clk_period/2, '1' after router_clk_period;
    wait for router_clk_period;
  end process router_clock_gen;

  tile_clock_gen : process is
  begin  -- process tile_clock_gen
    tile_clk <= '0' after router_clk_period, '1' after router_clk_period*2;
    wait for router_clk_period*2;
  end process tile_clock_gen;

  test : process is
  begin  -- process test
    reset <= '1' after 0 ns, '0' after 27 ns;
    wait;
  end process test;


end struct;

