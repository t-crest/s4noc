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
  signal   ser_txd           : std_logic;
  signal   ser_rxd           : std_logic;

begin  -- behav

  tile_test: entity work.tile_top
    port map (
      processor_clk => processor_clk,
      router_clk    => router_clk,
      reset         => reset,
      ser_txd       => ser_txd,
      ser_rxd       => ser_rxd);

  ser_rxd <= '0';
  
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