library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity noc is
	-- NxN nodes
	generic ( N : natural := 4;
		  WIDTH : natural := 16;
		  PERIOD_P : natural := 5
		);
	port(
		p_clk		: in std_logic;
		n_clk		: in std_logic;
		reset		: in std_logic;

		data_in		: in std_logic_vector(WIDTH-1 downto 0);
		data_out	: out std_logic_vector(WIDTH-1 downto 0)

	);
end entity noc;

architecture struct of noc is

	component noc_node
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
	end component;
   
		type link_n is array(0 to (N - 1)) of std_logic_vector(WIDTH-1 downto 0);
   	type link_m is array(0 to (N - 1)) of link_n;
   
   	signal north_in : link_m;
   	signal east_in : link_m;
   	signal south_in : link_m;
   	signal west_in : link_m;
   	signal north_out : link_m;
   	signal east_out : link_m;
  	signal south_out : link_m;
   	signal west_out : link_m;

	signal open_vector : std_logic_vector(WIDTH-1 downto 0);

begin
	-- generate connections
	nodes_m : for i in N-1 downto 0 generate
		nodes_n : for j in N-1 downto 0 generate
			node : noc_node
				generic map (WIDTH => WIDTH, 
					     PERIOD_P => PERIOD_P )
				port map (p_clk => p_clk, n_clk => n_clk, 
					reset => reset,
					north_in => north_in(i)(j),
					south_in => south_in(i)(j),
					east_in => east_in(i)(j),
					west_in => west_in(i)(j),
					north_out => north_out(i)(j),
					south_out => south_out(i)(j),
					east_out => east_out(i)(j),
					west_out => west_out(i)(j)
				);
		end generate nodes_n;
	end generate nodes_m;

	--outinterface
	north_in(0)(0) <= data_in;
	data_out <= north_out(0)(0);
	
	--interconnections	
	open_vector <= (others=>'0');
	links_m : for i in 0 to N-1  generate
		links_n : for j in 0 to N-1 generate				
			open_link_north : if ((i = 0) and not(j = 0)) generate
				north_in(i)(j) <= open_vector;
			end generate open_link_north;
			open_link_south : if (i = N) generate
				south_in(i)(j) <= open_vector;
			end generate open_link_south;
			open_link_west : if (j = 0) generate
				west_in(i)(j) <= open_vector;
			end generate open_link_west;
			open_link_east : if (j = N) generate
				east_in(i)(j) <= open_vector;
			end generate open_link_east;

			bottom : if ( i = (N-1) and j < (N-1) ) generate
				west_in(i)(j+1) <= east_out(i)(j);
				east_in(i)(j) <= west_out(i)(j+1);
			end generate bottom;
			right : if ( i < (N-1) and j = (N-1)) generate
				north_in(i+1)(j) <= south_out(i)(j);
				south_in(i)(j) <= north_out(i+1)(j);
			end generate right;
			center : if ( i < (N-1) and j < (N-1)) generate
				north_in(i+1)(j) <= south_out(i)(j);
				south_in(i)(j) <= north_out(i+1)(j);
				west_in(i)(j+1) <= east_out(i)(j);
				east_in(i)(j) <= west_out(i)(j+1);
			end generate center;
				
		end generate links_n;
	end generate links_m;

end architecture struct;

