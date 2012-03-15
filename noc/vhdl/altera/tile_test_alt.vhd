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
