library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity outnode is
	generic ( WIDTH	: natural; 
		  PERIOD_P : natural);
	port(
		clk	: in std_logic;
		reset	: in std_logic;
		in0	: in std_logic_vector(WIDTH-1 downto 0);
		in1	: in std_logic_vector(WIDTH-1 downto 0);
		in2	: in std_logic_vector(WIDTH-1 downto 0);
		in3	: in std_logic_vector(WIDTH-1 downto 0);

		reg_out	:out std_logic_vector(WIDTH-1 downto 0)
	);
end entity outnode;

architecture arc of outnode is

signal sel		: std_logic_vector(1 downto 0);
signal slt_cnt		: unsigned(PERIOD_P-1 downto 0);
signal next_slt		: unsigned(PERIOD_P-1 downto 0);
signal state		: std_logic_vector(3 downto 0);
signal next_q		: std_logic_vector(WIDTH-1 downto 0);

begin

	-- counter
	slot_counter : process (clk, reset, slt_cnt) is
	begin
		if reset = '1' then
			slt_cnt <= to_unsigned(0,PERIOD_P);
		elsif clk'event and clk = '1' then
			slt_cnt <= next_slt;
		end if;
		next_slt <= slt_cnt + 1;
	end process slot_counter;

	-- schedule table
	sel <= 	"00" when slt_cnt=0 or slt_cnt=4 or slt_cnt=8 or slt_cnt=12 else		--north
		"01" when slt_cnt=1 or slt_cnt=5 or slt_cnt=9 or slt_cnt=13 else		--south
		"10" when slt_cnt=2 or slt_cnt=6 or slt_cnt=10 or slt_cnt=14 else		--east
		"11";							--west


--	-- mux 4-to-1
--	CL : process (sel, in0, in1, in2, in3) is
--	begin
--		if sel = "00" then
--			next_state <= in0;
--		elsif sel = "01" then
--			next_state <= in1;
--		elsif sel = "10" then
--			next_state <= in2;
--		else
--			next_state <= in3;
--		end if;
--	end process CL;

	with sel select
		next_q <= 	in0 when "00",
				in1 when "01",
				in2 when "10",
				in3 when others;

	-- output assignment
	Reg : process (clk, reset, state) is
	begin
		if reset = '1' then
			reg_out <= (others =>'0');
		elsif clk'event and clk = '1' then
			reg_out <= next_q;
		end if;
	end process Reg;

end architecture arc;

