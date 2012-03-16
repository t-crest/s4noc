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
		count	: in unsigned(3 downto 0);
		sels	: out select_signals
		);
end router_ST;

architecture data of router_ST is
begin -- data

process(count) begin

	case count is

		when "0000" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "0001" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "0010" =>
			sels(0) <= 0;
			sels(1) <= 2;
			sels(2) <= 0;
			sels(3) <= 3;
			sels(4) <= 3;
		when "0011" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 1;
		when "0100" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 3;
			sels(3) <= 0;
			sels(4) <= 0;
		when "0101" =>
			sels(0) <= 3;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "0110" =>
			sels(0) <= 0;
			sels(1) <= 2;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 2;
		when "0111" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 1;
			sels(3) <= 0;
			sels(4) <= 3;
		when "1000" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 0;
		when "1001" =>
			sels(0) <= 0;
			sels(1) <= 0;
			sels(2) <= 0;
			sels(3) <= 0;
			sels(4) <= 1;
		when others => sels <= (others => 0);

	end case;
end process;

end data;
