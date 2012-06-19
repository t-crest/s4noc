--
--  Copyright 2012 Rasmus Bo S�rensen <rasmus@rbscloud.dk>,
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
  generic (
    TEST_TYPE : string := "NxN";
	 TEST_BOARD : string := "cyclonII");
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
  
 -- signal synch_reset, next_synch_reset : std_logic;
  
  	-- for generation of internal reset
	signal int_res			: std_logic;
	signal res_cnt			: unsigned(2 downto 0) := "000";	-- for the simulation

	attribute altera_attribute : string;
	attribute altera_attribute of res_cnt : signal is "POWER_UP_LEVEL=LOW";

begin  -- struct

--	process(processor_clk)
--	begin
--		if rising_edge(processor_clk) then
--			synch_reset <= next_synch_reset;
--			next_synch_reset <= reset;
--		end if;
--	end process;

	--
	--	internal reset generation
	--	should include the PLL lock signal
	--
	process(processor_clk)
	begin
		if rising_edge(processor_clk) then
			if (res_cnt/="111") and reset='0' then
				res_cnt <= res_cnt+1;
			end if;
			int_res <= not res_cnt(0) or not res_cnt(1) or not res_cnt(2);
		end if;
	end process;


	Cyclon2 : if TEST_BOARD = "cyclonII" generate
	  altpll_cyc2_inst : entity work.altpll_cyc2
		 port map (
		--	areset => reset,
			inclk0 => clk,
			c0     => processor_clk,
			c1     => router_clk,
			locked => locked_sig);
	end generate Cyclon2;
	
	Cyclon3 : if TEST_BOARD = "cyclonIII" generate
	  altpll_cyc2_inst : entity work.altpll_cyc2
		 port map (
		--	areset => reset,
			inclk0 => clk,
			c0     => processor_clk,
			c1     => router_clk,
			locked => locked_sig);
	end generate Cyclon3;
	
	

  NxN: if TEST_TYPE = "NxN" generate
    tile_top : entity work.noc
    port map (
      processor_clk => processor_clk,
      router_clk    => router_clk,
      reset         => int_res,
      ser_txd       => ser_txd,
      ser_rxd       => ser_rxd);
  end generate NxN;

  simple : if TEST_TYPE = "Simple" generate
    tile_top : entity work.tile_top
      port map (
        processor_clk => processor_clk,
        router_clk    => router_clk,
        reset         => int_res,
        ser_txd       => ser_txd,
        ser_rxd       => ser_rxd);  
  end generate simple;
  

end struct;
