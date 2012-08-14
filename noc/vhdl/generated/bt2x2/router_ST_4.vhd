-------------------------------------------------------------
-- router_ST_4.vhd
-- This is an auto generated file, do not edit by hand.
-------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;

entity router_ST_4 is
	generic (
		NI_NUM	: natural
		);
	port (
		count	: in unsigned(2 downto 0);
		sels	: out select_signals
		);
end router_ST_4;

architecture data of router_ST_4 is
begin -- data

process(count) begin

	case count is

		when "000" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "001" =>
			sels(N) <= D;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "010" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when "011" =>
			sels(N) <= D;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= S;
		when "100" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when others => sels <= (others => D);

	end case;
end process;

end data;
