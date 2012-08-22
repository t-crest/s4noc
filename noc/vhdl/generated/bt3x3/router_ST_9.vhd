-------------------------------------------------------------
-- router_ST_9.vhd
-- This is an auto generated file, do not edit by hand.
-------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;

entity router_ST_9 is
	generic (
		NI_NUM	: natural
		);
	port (
		count	: in unsigned(3 downto 0);
		sels	: out select_signals
		);
end router_ST_9;

architecture data of router_ST_9 is
begin -- data

process(count) begin

	sels(D) <= D;
	case count is

		when "0000" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "0001" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "0010" =>
			sels(N) <= D;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= S;
			sels(L) <= W;
		when "0011" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= W;
			sels(W) <= L;
			sels(L) <= E;
		when "0100" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= E;
			sels(W) <= D;
			sels(L) <= N;
		when "0101" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= N;
		when "0110" =>
			sels(N) <= D;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= S;
		when "0111" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= W;
		when "1000" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= L;
			sels(L) <= N;
		when "1001" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= E;
		when others => sels <= (others => D);

	end case;
end process;

end data;
