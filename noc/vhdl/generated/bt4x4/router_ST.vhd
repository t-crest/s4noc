-------------------------------------------------------------
-- router_ST.vhd
-- This is an auto generated file, do not edit by hand.
-------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.leros_types.all;
use work.noc_types.all;

entity router_ST is
	port (
		count	: in unsigned(4 downto 0);
		sels	: out select_signals
		);
end router_ST;

architecture data of router_ST is
begin -- data

process(count) begin

	case count is

		when "00000" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "00001" =>
			sels(0) <= 1;
			sels(1) <= 2;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "00010" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "00011" =>
			sels(0) <= 3;
			sels(1) <= 1;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "00100" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 3;
		when "00101" =>
			sels(0) <= 1;
			sels(1) <= 1;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "00110" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 3;
		when "00111" =>
			sels(0) <= 1;
			sels(1) <= 2;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 3;
		when "01000" =>
			sels(0) <= 3;
			sels(1) <= 1;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 2;
		when "01001" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 2;
		when "01010" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "01011" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 3;
			sels(4) <= 3;
		when "01100" =>
			sels(0) <= 1;
			sels(1) <= 2;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 1;
		when "01101" =>
			sels(0) <= 0;
			sels(1) <= 1;
			sels(2) <= 1;
			sels(3) <= 0;
			sels(4) <= 2;
		when "01110" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 1;
			sels(4) <= 3;
		when "01111" =>
			sels(0) <= 0;
			sels(1) <= 2;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 1;
		when "10000" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 1;
			sels(3) <= 0;
			sels(4) <= 3;
		when "10001" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "10010" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 1;
		when others => sels <= (others => 0);

	end case;
end process;

end data;
