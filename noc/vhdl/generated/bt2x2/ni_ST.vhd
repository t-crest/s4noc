-------------------------------------------------------------
-- ni_ST.vhd
-- This is an auto generated file, do not edit by hand.
-------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.leros_types.all;
use work.noc_types.all;

entity ni_ST is
	generic (
		NI_NUM	: natural);
	port (
		count	: in unsigned(2 downto 0);
		dest	: out integer range 0 to 4;
		src	: out integer range 0 to 4
		);
end ni_ST;

architecture data of ni_ST is
begin -- data

	NI_NUM0 : if NI_NUM = 0 generate
	process(count) begin

		case count is

			when "000" =>
				dest <= 2;
				src <= 0;
			when "001" =>
				dest <= 1;
				src <= 0;
			when "010" =>
				dest <= 0;
				src <= 3;
			when "011" =>
				dest <= 3;
				src <= 2;
			when "100" =>
				dest <= 0;
				src <= 1;
			when others =>
				dest <= 0;
				src <= 0;

		end case;
	end process;

	end generate NI_NUM0;

	NI_NUM1 : if NI_NUM = 1 generate
	process(count) begin

		case count is

			when "000" =>
				dest <= 3;
				src <= 1;
			when "001" =>
				dest <= 0;
				src <= 1;
			when "010" =>
				dest <= 1;
				src <= 2;
			when "011" =>
				dest <= 2;
				src <= 3;
			when "100" =>
				dest <= 1;
				src <= 0;
			when others =>
				dest <= 1;
				src <= 1;

		end case;
	end process;

	end generate NI_NUM1;

	NI_NUM2 : if NI_NUM = 2 generate
	process(count) begin

		case count is

			when "000" =>
				dest <= 0;
				src <= 2;
			when "001" =>
				dest <= 3;
				src <= 2;
			when "010" =>
				dest <= 2;
				src <= 1;
			when "011" =>
				dest <= 1;
				src <= 0;
			when "100" =>
				dest <= 2;
				src <= 3;
			when others =>
				dest <= 2;
				src <= 2;

		end case;
	end process;

	end generate NI_NUM2;

	NI_NUM3 : if NI_NUM = 3 generate
	process(count) begin

		case count is

			when "000" =>
				dest <= 1;
				src <= 3;
			when "001" =>
				dest <= 2;
				src <= 3;
			when "010" =>
				dest <= 3;
				src <= 0;
			when "011" =>
				dest <= 0;
				src <= 1;
			when "100" =>
				dest <= 3;
				src <= 2;
			when others =>
				dest <= 3;
				src <= 3;

		end case;
	end process;

	end generate NI_NUM3;

end data;
