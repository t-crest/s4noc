--
--  Copyright 2012 Rasmus Bo Sørensen <rasmus@rbscloud.dk>,
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

library work;
use work.noc_types.all;
use work.leros_types.all;

entity tb_NI is

end tb_NI;

architecture struct of tb_NI is
  constant stable_length          : natural := 9;
  constant router_clk_period      : time    := 5 ns;
  signal   router_clk             : std_logic;
  signal   tile_clk             : std_logic;
  signal   reset                  : std_logic;
  signal   router_f_1, router_f_2 : network_link_forward;
  signal   router_b_1, router_b_2 : network_link_backward;
  signal   tile_in_1, tile_in_2   : io_in_type;
  signal   tile_out_1, tile_out_2 : io_out_type;
  
begin  -- struct

  ni_1 : entity work.ni_ram
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

  
  ni_2 : entity work.ni_ram
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

