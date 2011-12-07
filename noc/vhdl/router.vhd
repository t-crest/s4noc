library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity router is
	generic ( WIDTH	: natural := 8; 
		  PERIOD_P : natural := 5  );
	port(
		clk		: in std_logic;
		reset		: in std_logic;

		north_in	: in std_logic_vector(WIDTH-1 downto 0);
		south_in	: in std_logic_vector(WIDTH-1 downto 0);
		east_in		: in std_logic_vector(WIDTH-1 downto 0);
		west_in		: in std_logic_vector(WIDTH-1 downto 0);
		local_in	: in std_logic_vector(WIDTH-1 downto 0);

		north_out	: out std_logic_vector(WIDTH-1 downto 0);
		south_out	: out std_logic_vector(WIDTH-1 downto 0);
		east_out	: out std_logic_vector(WIDTH-1 downto 0);
		west_out	: out std_logic_vector(WIDTH-1 downto 0);
		local_out	: out std_logic_vector(WIDTH-1 downto 0)
	);
end entity router;


architecture struct of router is

	component outnode
		generic ( WIDTH	: natural; 
			  PERIOD_P : natural);
		port (	
			clk	: in std_logic;
			reset	: in std_logic;
			in0	: in std_logic_vector(WIDTH-1 downto 0);
			in1	: in std_logic_vector(WIDTH-1 downto 0);
			in2	: in std_logic_vector(WIDTH-1 downto 0);
			in3	: in std_logic_vector(WIDTH-1 downto 0);

			reg_out	:out std_logic_vector(WIDTH-1 downto 0)
		);
	end component;
	signal sel		: std_logic_vector(1 downto 0);

begin

	north_output : outnode
		generic map (WIDTH=>WIDTH,
			     PERIOD_P=>PERIOD_P)
		port map (in0=>local_in, in1=>south_in,
			in2=>east_in, in3=>west_in,
			clk=>clk, reset=>reset,
			reg_out=>north_out);

	south_output : outnode
		generic map (WIDTH=>WIDTH,
			     PERIOD_P=>PERIOD_P)
		port map(in0=>north_in, in1=>local_in,
			in2=>east_in, in3=>west_in,
			clk=>clk, reset=>reset,
			reg_out=>south_out);


	east_output : outnode
		generic map (WIDTH=>WIDTH,
			     PERIOD_P=>PERIOD_P)
		port map(in0=>north_in, in1=>south_in,
			in2=>local_in, in3=>west_in,
			clk=>clk, reset=>reset,
			reg_out=>east_out);


	west_output : outnode
		generic map (WIDTH=>WIDTH,
			     PERIOD_P=>PERIOD_P)
		port map(in0=>north_in, in1=>south_in,
			in2=>east_in, in3=>local_in,
			clk=>clk, reset=>reset,
			reg_out=>west_out);


	local_output : outnode
		generic map (WIDTH=>WIDTH,
			     PERIOD_P=>PERIOD_P)
		port map(in0=>north_in, in1=>south_in,
			in2=>east_in, in3=>west_in,
			clk=>clk, reset=>reset,
			reg_out=>local_out);

	
end architecture struct;

