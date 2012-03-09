library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.leros_types.all;
use work.noc_types.all;

entity tile is
  generic (
    UART          : boolean := false;
    TOTAL_NI_NUM  : natural;
    NI_NUM        : natural;
    stable_length : natural);
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
  signal processor_out     : io_out_type;
  signal processor_in      : io_in_type;
  signal processor_out_mux : io_out_type;
  signal processor_in_mux  : io_in_type;

  signal local_in  : network_link_forward;
  signal tile_tx_b : network_link_backward;
  signal local_out : network_link_forward;

  signal uart_addr   : std_logic;
  signal uart_rd     : std_logic;
  signal uart_wr     : std_logic;
  signal uart_rddata : std_logic_vector(15 downto 0);
  
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
        clk_freq  => 50000000,
        baud_rate => 115200,
        txf_depth => 1,
        rxf_depth => 1)
      port map (
        clk     => processor_clk,
        reset   => reset,
        address => uart_addr,
        wr_data => processor_out.wrdata,
        rd      => uart_rd,
        wr      => uart_wr,
        rd_data => uart_rddata,

        txd => ser_txd,
        rxd => ser_rxd);

    ua_mux : process (processor_out, uart_rddata, processor_in_mux)
    begin  -- process ua_mux
      uart_addr                <= '0';
      uart_rd                  <= '0';
      uart_wr                  <= '0';
      processor_out_mux.addr   <= (others => '0');
      processor_out_mux.wrdata <= (others => '0');
      processor_out_mux.rd     <= '0';
      processor_out_mux.wr     <= '0';
      processor_in.rddata      <= (others => '0');
      if processor_out.addr(7 downto 1) = std_logic_vector(to_unsigned(63, 7)) then
        uart_addr           <= processor_out.addr(0);
        uart_rd             <= processor_out.rd;
        uart_wr             <= processor_out.wr;
        processor_in.rddata <= uart_rddata;
      elsif processor_out.addr(7 downto 1) /= std_logic_vector(to_unsigned(63, 7)) then
        processor_out_mux <= processor_out;
        processor_in      <= processor_in_mux;
      end if;
      
    end process ua_mux;
    
  end generate gen_ua;

  not_gen_ua : if not UART generate
    processor_out_mux <= processor_out;
    processor_in      <= processor_in_mux;
  end generate not_gen_ua;

  ni : entity work.ni
    generic map (
      TOTAL_NI_NUM  => TOTAL_NI_NUM,
      NI_NUM        => NI_NUM,
      stable_length => stable_length)
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,
      tile_tx_f     => local_in,
      tile_tx_b     => tile_tx_b,
      tile_rx_f     => local_out,
      tile_rx_b     => open,
      processor_out => processor_out_mux,
      processor_in  => processor_in_mux);

  
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
