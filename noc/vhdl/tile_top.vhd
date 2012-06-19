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
      UART => true,
      NI_NUM => 0)
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
      UART => false,
      NI_NUM => 1)
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
