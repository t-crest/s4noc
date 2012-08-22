-------------------------------------------------------------
-- router_ST_36.vhd
-- This is an auto generated file, do not edit by hand.
-------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;

entity router_ST_36 is
	generic (
		NI_NUM	: natural
		);
	port (
		count	: in unsigned(5 downto 0);
		sels	: out select_signals
		);
end router_ST_36;

architecture data of router_ST_36 is
begin -- data

process(count) begin

	sels(D) <= D;
	case count is

		when "000000" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "000001" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= D;
		when "000010" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= D;
		when "000011" =>
			sels(N) <= D;
			sels(E) <= S;
			sels(S) <= W;
			sels(W) <= N;
			sels(L) <= D;
		when "000100" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= N;
			sels(W) <= D;
			sels(L) <= E;
		when "000101" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= L;
			sels(L) <= N;
		when "000110" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= E;
			sels(L) <= W;
		when "000111" =>
			sels(N) <= E;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= S;
			sels(L) <= D;
		when "001000" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= N;
			sels(W) <= D;
			sels(L) <= E;
		when "001001" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= N;
			sels(L) <= W;
		when "001010" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= E;
			sels(L) <= S;
		when "001011" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= L;
			sels(L) <= E;
		when "001100" =>
			sels(N) <= S;
			sels(E) <= D;
			sels(S) <= W;
			sels(W) <= E;
			sels(L) <= D;
		when "001101" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= N;
			sels(W) <= D;
			sels(L) <= E;
		when "001110" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= S;
			sels(L) <= N;
		when "001111" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= E;
			sels(L) <= W;
		when "010000" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= E;
		when "010001" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= S;
			sels(L) <= N;
		when "010010" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= E;
			sels(L) <= W;
		when "010011" =>
			sels(N) <= W;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= L;
			sels(L) <= E;
		when "010100" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= E;
		when "010101" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= N;
			sels(L) <= W;
		when "010110" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= E;
			sels(L) <= S;
		when "010111" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= E;
		when "011000" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= W;
			sels(W) <= D;
			sels(L) <= D;
		when "011001" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= W;
			sels(W) <= S;
			sels(L) <= N;
		when "011010" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= N;
			sels(W) <= D;
			sels(L) <= E;
		when "011011" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= N;
		when "011100" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= N;
			sels(W) <= D;
			sels(L) <= W;
		when "011101" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= N;
			sels(L) <= W;
		when "011110" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= S;
			sels(L) <= E;
		when "011111" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= W;
			sels(W) <= D;
			sels(L) <= E;
		when "100000" =>
			sels(N) <= S;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= N;
		when "100001" =>
			sels(N) <= L;
			sels(E) <= W;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= S;
		when "100010" =>
			sels(N) <= L;
			sels(E) <= S;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when "100011" =>
			sels(N) <= S;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when "100100" =>
			sels(N) <= D;
			sels(E) <= L;
			sels(S) <= W;
			sels(W) <= D;
			sels(L) <= S;
		when "100101" =>
			sels(N) <= D;
			sels(E) <= W;
			sels(S) <= L;
			sels(W) <= D;
			sels(L) <= N;
		when "100110" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= N;
			sels(W) <= D;
			sels(L) <= W;
		when "100111" =>
			sels(N) <= L;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= N;
		when "101000" =>
			sels(N) <= D;
			sels(E) <= L;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= S;
		when "101001" =>
			sels(N) <= D;
			sels(E) <= D;
			sels(S) <= D;
			sels(W) <= D;
			sels(L) <= W;
		when others => sels <= (others => D);

	end case;
end process;

end data;
