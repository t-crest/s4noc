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
