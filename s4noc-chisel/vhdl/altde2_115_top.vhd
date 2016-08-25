library ieee;
use ieee.std_logic_1164.all;

entity skeleton_top is port(
	clk : in std_logic;
	led : out std_logic );
end entity skeleton_top;

architecture rtl of skeleton_top is
	component Skeleton is port(
		clk : in std_logic;
		reset : in std_logic;
		io_led : out std_logic );
	end component;

	signal res : std_logic;
	signal s_io_led : std_logic;

begin
	res <= '0';
	led <= s_io_led;
	skel : Skeleton port map(clk, res, s_io_led);

end architecture rtl;
