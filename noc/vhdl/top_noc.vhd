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
use ieee.numeric_std.all;

use work.leros_types.all;

entity top_noc is
	port ( 
		clk		: in std_logic;
		reset		: in std_logic;
		
		data_in		: in std_logic_vector(15 downto 0);
		data_out	: out std_logic_vector(15 downto 0)
	);
end entity top_noc;

architecture rtl of top_noc is

--	signal inclk0_sig		: std_logic;
	signal c0_sig			: std_logic;
	signal c1_sig			: std_logic;
        signal locked_sig		: std_logic;
	signal int_res			: std_logic;
	signal res_cnt			: unsigned(2 downto 0) := "000";	-- for the simulation

begin

	pll_cyc3_inst : entity work.pll_cyc3
	port map (
                inclk0   => clk,
                c0       => c0_sig,
                c1       => c1_sig,
                locked   => locked_sig
        );

	noc_inst : entity work.noc
	generic map (
--		N 	=> 4,
		WIDTH 	=> 16,
		PERIOD_P => 5
	)
	port map (
		p_clk	=> c0_sig,
		n_clk	=> c1_sig,
		reset	=> int_res,

		data_in => data_in,
		data_out => data_out
	);

	--	internal reset generation
	process(c0_sig)
	begin
		if rising_edge(c0_sig) then
			if (res_cnt/="111") then
				res_cnt <= res_cnt+1;
			end if;

			int_res <= not res_cnt(0) or not res_cnt(1) or not res_cnt(2);
		end if;
	end process;


end architecture rtl;
