library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;
use work.leros_types.all;

entity tile_top is
  port (
    processor_clk : in std_logic;
    router_clk    : in std_logic;
    reset         : in std_logic;

    ser_txd : out std_logic;
    ser_rxd : in  std_logic
    );
end entity tile_top;

architecture struct of tile_top is


  signal east_link : network_link_forward;
  signal west_link : network_link_forward;
  signal zero_link : network_link_forward;

begin
  zero_link.data       <= (others => '0');
  zero_link.data_valid <= '0';


  tile_1 : entity work.tile
    generic map (
      UART => true)
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,
      north_in      => zero_link,
      south_in      => zero_link,
      east_in       => west_link,
      west_in       => zero_link,
      north_out     => open,
      south_out     => open,
      east_out      => east_link,
      west_out      => open,
      ser_txd       => ser_txd,
      ser_rxd       => ser_rxd);

  tile_2 : entity work.tile
    generic map (
      UART => false)
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,
      north_in      => zero_link,
      south_in      => zero_link,
      east_in       => zero_link,
      west_in       => east_link,
      north_out     => open,
      south_out     => open,
      east_out      => open,
      west_out      => west_link,
      ser_txd       => open,
      ser_rxd       => '0');
  


end architecture struct;
