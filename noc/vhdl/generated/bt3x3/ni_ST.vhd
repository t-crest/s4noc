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
		count	: in unsigned(3 downto 0);
		dest	: out integer range 0 to 9;
		src	: out integer range 0 to 9
		);
end ni_ST;

architecture data of ni_ST is
begin -- data

	NI_NUM0 : if NI_NUM = 0 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 4;
				src <= 0;
			when "0001" =>
				dest <= 5;
				src <= 0;
			when "0010" =>
				dest <= 0;
				src <= 5;
			when "0011" =>
				dest <= 6;
				src <= 4;
			when "0100" =>
				dest <= 1;
				src <= 8;
			when "0101" =>
				dest <= 3;
				src <= 7;
			when "0110" =>
				dest <= 2;
				src <= 3;
			when "0111" =>
				dest <= 0;
				src <= 2;
			when "1000" =>
				dest <= 7;
				src <= 6;
			when "1001" =>
				dest <= 8;
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

			when "0000" =>
				dest <= 5;
				src <= 1;
			when "0001" =>
				dest <= 3;
				src <= 1;
			when "0010" =>
				dest <= 1;
				src <= 3;
			when "0011" =>
				dest <= 7;
				src <= 5;
			when "0100" =>
				dest <= 2;
				src <= 6;
			when "0101" =>
				dest <= 4;
				src <= 8;
			when "0110" =>
				dest <= 0;
				src <= 4;
			when "0111" =>
				dest <= 1;
				src <= 0;
			when "1000" =>
				dest <= 8;
				src <= 7;
			when "1001" =>
				dest <= 6;
				src <= 2;
			when others =>
				dest <= 1;
				src <= 1;

		end case;
	end process;

	end generate NI_NUM1;

	NI_NUM2 : if NI_NUM = 2 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 3;
				src <= 2;
			when "0001" =>
				dest <= 4;
				src <= 2;
			when "0010" =>
				dest <= 2;
				src <= 4;
			when "0011" =>
				dest <= 8;
				src <= 3;
			when "0100" =>
				dest <= 0;
				src <= 7;
			when "0101" =>
				dest <= 5;
				src <= 6;
			when "0110" =>
				dest <= 1;
				src <= 5;
			when "0111" =>
				dest <= 2;
				src <= 1;
			when "1000" =>
				dest <= 6;
				src <= 8;
			when "1001" =>
				dest <= 7;
				src <= 0;
			when others =>
				dest <= 2;
				src <= 2;

		end case;
	end process;

	end generate NI_NUM2;

	NI_NUM3 : if NI_NUM = 3 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 7;
				src <= 3;
			when "0001" =>
				dest <= 8;
				src <= 3;
			when "0010" =>
				dest <= 3;
				src <= 8;
			when "0011" =>
				dest <= 0;
				src <= 7;
			when "0100" =>
				dest <= 4;
				src <= 2;
			when "0101" =>
				dest <= 6;
				src <= 1;
			when "0110" =>
				dest <= 5;
				src <= 6;
			when "0111" =>
				dest <= 3;
				src <= 5;
			when "1000" =>
				dest <= 1;
				src <= 0;
			when "1001" =>
				dest <= 2;
				src <= 4;
			when others =>
				dest <= 3;
				src <= 3;

		end case;
	end process;

	end generate NI_NUM3;

	NI_NUM4 : if NI_NUM = 4 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 8;
				src <= 4;
			when "0001" =>
				dest <= 6;
				src <= 4;
			when "0010" =>
				dest <= 4;
				src <= 6;
			when "0011" =>
				dest <= 1;
				src <= 8;
			when "0100" =>
				dest <= 5;
				src <= 0;
			when "0101" =>
				dest <= 7;
				src <= 2;
			when "0110" =>
				dest <= 3;
				src <= 7;
			when "0111" =>
				dest <= 4;
				src <= 3;
			when "1000" =>
				dest <= 2;
				src <= 1;
			when "1001" =>
				dest <= 0;
				src <= 5;
			when others =>
				dest <= 4;
				src <= 4;

		end case;
	end process;

	end generate NI_NUM4;

	NI_NUM5 : if NI_NUM = 5 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 6;
				src <= 5;
			when "0001" =>
				dest <= 7;
				src <= 5;
			when "0010" =>
				dest <= 5;
				src <= 7;
			when "0011" =>
				dest <= 2;
				src <= 6;
			when "0100" =>
				dest <= 3;
				src <= 1;
			when "0101" =>
				dest <= 8;
				src <= 0;
			when "0110" =>
				dest <= 4;
				src <= 8;
			when "0111" =>
				dest <= 5;
				src <= 4;
			when "1000" =>
				dest <= 0;
				src <= 2;
			when "1001" =>
				dest <= 1;
				src <= 3;
			when others =>
				dest <= 5;
				src <= 5;

		end case;
	end process;

	end generate NI_NUM5;

	NI_NUM6 : if NI_NUM = 6 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 1;
				src <= 6;
			when "0001" =>
				dest <= 2;
				src <= 6;
			when "0010" =>
				dest <= 6;
				src <= 2;
			when "0011" =>
				dest <= 3;
				src <= 1;
			when "0100" =>
				dest <= 7;
				src <= 5;
			when "0101" =>
				dest <= 0;
				src <= 4;
			when "0110" =>
				dest <= 8;
				src <= 0;
			when "0111" =>
				dest <= 6;
				src <= 8;
			when "1000" =>
				dest <= 4;
				src <= 3;
			when "1001" =>
				dest <= 5;
				src <= 7;
			when others =>
				dest <= 6;
				src <= 6;

		end case;
	end process;

	end generate NI_NUM6;

	NI_NUM7 : if NI_NUM = 7 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 2;
				src <= 7;
			when "0001" =>
				dest <= 0;
				src <= 7;
			when "0010" =>
				dest <= 7;
				src <= 0;
			when "0011" =>
				dest <= 4;
				src <= 2;
			when "0100" =>
				dest <= 8;
				src <= 3;
			when "0101" =>
				dest <= 1;
				src <= 5;
			when "0110" =>
				dest <= 6;
				src <= 1;
			when "0111" =>
				dest <= 7;
				src <= 6;
			when "1000" =>
				dest <= 5;
				src <= 4;
			when "1001" =>
				dest <= 3;
				src <= 8;
			when others =>
				dest <= 7;
				src <= 7;

		end case;
	end process;

	end generate NI_NUM7;

	NI_NUM8 : if NI_NUM = 8 generate
	process(count) begin

		case count is

			when "0000" =>
				dest <= 0;
				src <= 8;
			when "0001" =>
				dest <= 1;
				src <= 8;
			when "0010" =>
				dest <= 8;
				src <= 1;
			when "0011" =>
				dest <= 5;
				src <= 0;
			when "0100" =>
				dest <= 6;
				src <= 4;
			when "0101" =>
				dest <= 2;
				src <= 3;
			when "0110" =>
				dest <= 7;
				src <= 2;
			when "0111" =>
				dest <= 8;
				src <= 7;
			when "1000" =>
				dest <= 3;
				src <= 5;
			when "1001" =>
				dest <= 4;
				src <= 6;
			when others =>
				dest <= 8;
				src <= 8;

		end case;
	end process;

	end generate NI_NUM8;

end data;
