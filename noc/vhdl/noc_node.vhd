library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.leros_types.all;


entity noc_node is
	generic ( WIDTH	: natural; 
		  PERIOD_P : natural );
	port (	p_clk		: in std_logic;
		n_clk		: in std_logic;
		reset		: in std_logic;

		north_in	: in std_logic_vector(WIDTH-1 downto 0);
		south_in	: in std_logic_vector(WIDTH-1 downto 0);
		east_in		: in std_logic_vector(WIDTH-1 downto 0);
		west_in		: in std_logic_vector(WIDTH-1 downto 0);

		north_out	: out std_logic_vector(WIDTH-1 downto 0);
		south_out	: out std_logic_vector(WIDTH-1 downto 0);
		east_out	: out std_logic_vector(WIDTH-1 downto 0);
		west_out	: out std_logic_vector(WIDTH-1 downto 0)

);
end entity noc_node;

architecture struct of noc_node is
	component router
		generic ( WIDTH	: natural; 
			  PERIOD_P : natural );
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
	end component;
	component leros
		port (
			clk : in std_logic;
			reset : in std_logic;
			ioout : out io_out_type;
			ioin : in io_in_type
		);
	end component;
	signal noc_in		: std_logic_vector(WIDTH-1 downto 0);
	signal noc_out		: std_logic_vector(WIDTH-1 downto 0);
	signal p_out		: io_out_type;
	signal p_in			: io_in_type;

begin

	noc_in <= p_out.wrdata;
	p_in.rddata <= noc_out;
	
	processor_node : leros
		port map ( clk => p_clk, reset => reset,
				ioout => p_out,
				ioin => p_in
		);

	router_node : router
		generic map (WIDTH => WIDTH,
			     PERIOD_P => PERIOD_P)
		port map (clk => n_clk, reset => reset,
				north_in => north_in,
				south_in => south_in,
				east_in => east_in,
				west_in => west_in,
				local_in => noc_in,
				north_out => north_out,
				south_out => south_out,
				east_out => east_out,
				west_out => west_out,
				local_out => noc_out
		);

end architecture struct;
