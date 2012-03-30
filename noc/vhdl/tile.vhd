--
--  Copyright 2012 Rasmus Bo Soerensen <rasmus@rbscloud.dk>,
--                 Technical University of Denmark, DTU Informatics. 
--  All rights reserved.
--
-- Redistribution and use in source and binary forms, with or without
-- modification, are permitted provided that the following conditions are met:
-- 
--    1. Redistributions of source code must retain the above copyright notice,
--       this list of conditions and the following disclaimer.
-- 
--    2. Redistributions in binary form must reproduce the above copyright
--       notice, this list of conditions and the following disclaimer in the
--       documentation and/or other materials provided with the distribution.
-- 
-- THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ``AS IS'' AND ANY EXPRESS
-- OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
-- OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
-- NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
-- DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
-- (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
-- LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
-- ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
-- (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
-- THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-- 
-- The views and conclusions contained in the software and documentation are
-- those of the authors and should not be interpreted as representing official
-- policies, either expressed or implied, of the copyright holder.
--
--

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
  -- signal tile_tx_b : network_link_backward;
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
        clk_freq  => 100000000,
        baud_rate => 115200,
        txf_depth => 1,
        rxf_depth => 2)
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
      if processor_out.addr(7 downto 1) = std_logic_vector(to_unsigned(127, 7)) then
        uart_addr           <= processor_out.addr(0);
        uart_rd             <= processor_out.rd;
        uart_wr             <= processor_out.wr;
        processor_in.rddata <= uart_rddata;
      elsif processor_out.addr(7 downto 1) /= std_logic_vector(to_unsigned(127, 7)) then
        processor_out_mux <= processor_out;
        processor_in      <= processor_in_mux;
      end if;

      if processor_out.addr = std_logic_vector(to_unsigned(253, processor_out.addr'length)) and processor_out.rd = '1' then
        processor_in.rddata <= std_logic_vector(to_unsigned(NI_NUM, processor_in.rddata'length));
      elsif processor_out.addr = std_logic_vector(to_unsigned(252, processor_out.addr'length)) and processor_out.rd = '1' then
        processor_in.rddata <= std_logic_vector(to_unsigned(TOTAL_NI_NUM, processor_in.rddata'length));
      end if;
    end process ua_mux;
    
  end generate gen_ua;

  not_gen_ua : if not UART generate

    -- CPU register, for ease of programming.
    cpu_reg : process (processor_out.addr, processor_in_mux)
    begin  -- process cpu_reg
      processor_out_mux <= processor_out;
      processor_in      <= processor_in_mux;
      if processor_out.addr = std_logic_vector(to_unsigned(253, processor_out.addr'length)) and processor_out.rd = '1' then
        processor_in.rddata <= std_logic_vector(to_unsigned(NI_NUM, processor_in.rddata'length));
      elsif processor_out.addr = std_logic_vector(to_unsigned(252, processor_out.addr'length)) and processor_out.rd = '1' then
        processor_in.rddata <= std_logic_vector(to_unsigned(TOTAL_NI_NUM, processor_in.rddata'length));
      end if;
    end process cpu_reg;
  end generate not_gen_ua;





  ni : entity work.ni_ram
    generic map (
      TOTAL_NI_NUM  => TOTAL_NI_NUM,
      NI_NUM        => NI_NUM,
      stable_length => stable_length)
    port map (
      router_clk    => router_clk,
      processor_clk => processor_clk,
      reset         => reset,
      tile_tx_f     => local_in,
      -- tile_tx_b     => tile_tx_b,
      tile_rx_f     => local_out,
      --  tile_rx_b     => open,
      processor_out => processor_out_mux,
      processor_in  => processor_in_mux);

  
  router_node : entity work.router
    generic map (
      stable_length => stable_length)
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
