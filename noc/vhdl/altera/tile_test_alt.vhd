library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;

use work.noc_types.all;
use work.leros_types.all;

entity tile_test_alt is
  
  port (
    clk     : in  std_logic;
    reset   : in  std_logic;
    ser_txd : out std_logic;
    ser_rxd : in  std_logic);

end tile_test_alt;

architecture struct of tile_test_alt is

  signal router_clk    : std_logic;
  signal processor_clk : std_logic;
  signal locked_sig    : std_logic;

begin  -- struct

  altpll_cyc2_inst : entity work.altpll_cyc2
    port map (
      areset => reset,
      inclk0 => clk,
      c0     => processor_clk,
      c1     => router_clk,
      locked => locked_sig
      );

  tile_top : entity work.tile_top
    port map (
      processor_clk => processor_clk,
      router_clk    => router_clk,
      reset         => reset,
      ser_txd       => ser_txd,
      ser_rxd       => ser_rxd);

end struct;
