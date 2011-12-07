library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.leros_types.all;

entity top is
	port ( 
		clk		: in std_logic;
		reset		: in std_logic;
		
		data_in		: in std_logic_vector(15 downto 0);
		data_out	: out std_logic_vector(15 downto 0)
	);
end entity top;

architecture rtl of top is

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
