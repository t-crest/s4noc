--
-- Copyright: 2013, Technical University of Denmark, DTU Compute
-- Author: Martin Schoeberl (martin@jopdesign.com)
-- License: Simplified BSD License
--

-- Hardware Hello World with Chisel - VHDL top level

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity blink_top is
	port(
		clk : in  std_logic;
		--		rst : in std_logic;
		led : out std_logic
	);
end entity blink_top;

architecture rtl of blink_top is

component blink is port (
	clk : in std_logic;
	reset : in std_logic;
    io_led : out std_logic
);
end component;

	signal blk : std_logic;
	
begin

	bl: blink port map (
		clk, '0', blk
	);
	
	led <= blk;
	
end architecture rtl;
