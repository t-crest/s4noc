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
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "00001" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "00010" =>
			sels(N) <= D;
			sels(E) <= S;
			sels(S) <= W;
			sels(W) <= D;
			sels(L) <= D;
		when "00011" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= N;
		when "00100" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when "00101" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= L;
			sels(L) <= D;
		when "00110" =>
			sels(N) <= E;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when "00111" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when "01000" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= S;
		when "01001" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= W;
			sels(W) <= D;
			sels(L) <= S;
		when "01010" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= N;
		when "01011" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= S;
			sels(L) <= W;
		when "01100" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= E;
		when "01101" =>
			sels(N) <= D;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= S;
		when "01110" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= N;
			sels(L) <= W;
		when "01111" =>
			sels(N) <= D;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= E;
		when "10000" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= W;
		when "10001" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= L;
			sels(L) <= N;
		when "10010" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= E;
		when others => sels <= (others => D);

	end case;
end process;

end data;
