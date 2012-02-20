library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;

library work;
use work.noc_types.all;
use work.leros_types.all;

entity tb_noc is

end tb_noc;

architecture behav of tb_noc is
  constant router_clk_period : time := 5 ns;
  signal   router_clk        : std_logic;
  signal   processor_clk     : std_logic;
  signal   reset             : std_logic;
  signal   link_east         : network_link_forward;
  signal   link_west         : network_link_forward;
  signal   zero_network_link : network_link_forward;
  signal   ser_txd           : std_logic;
  signal   ser_rxd           : std_logic;

begin  -- behav

  zero_network_link.data       <= (others => '0');
  zero_network_link.data_valid <= '0';


  tile1 : entity work.tile
    generic map (
      UART => true)
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,

      north_in => zero_network_link,
      south_in => zero_network_link,
      east_in  => link_west,
      west_in  => zero_network_link,

      north_out => open,
      south_out => open,
      east_out  => link_east,
      west_out  => open,

      ser_txd => ser_txd,
      ser_rxd => ser_rxd);


  tile2 : entity work.tile
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,

      north_in => zero_network_link,
      south_in => zero_network_link,
      east_in  => zero_network_link,
      west_in  => link_east,

      north_out => open,
      south_out => open,
      east_out  => open,
      west_out  => link_west,

      ser_txd => open,
      ser_rxd => '0');

  router_clock_gen : process is
  begin  -- process clock_gen
    router_clk <= '0' after router_clk_period/2, '1' after router_clk_period;
    wait for router_clk_period;
  end process router_clock_gen;

  processor_clock_gen : process is
  begin  -- process tile_clock_gen
    processor_clk <= '0' after router_clk_period, '1' after router_clk_period*2;
    wait for router_clk_period*2;
  end process processor_clock_gen;

  test : process is
  begin  -- process test
    reset <= '1' after 0 ns, '0' after 27 ns;
    wait;
  end process test;


end behav;
