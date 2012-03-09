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
		count	: in unsigned(4 downto 0);
		dest	: out integer range 0 to 9;
		src	: out integer range 0 to 9
		);
end ni_ST;

architecture data of ni_ST is
begin -- data

	NI_NUM0 : if NI_NUM = 0 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 8;
				src <= 0;
			when "00001" =>
				dest <= 0;
				src <= 0;
			when "00010" =>
				dest <= 0;
				src <= 0;
			when "00011" =>
				dest <= 0;
				src <= 0;
			when "00100" =>
				dest <= 0;
				src <= 0;
			when "00101" =>
				dest <= 4;
				src <= 6;
			when "00110" =>
				dest <= 5;
				src <= 0;
			when "00111" =>
				dest <= 0;
				src <= 0;
			when "01000" =>
				dest <= 0;
				src <= 0;
			when "01001" =>
				dest <= 2;
				src <= 0;
			when "01010" =>
				dest <= 7;
				src <= 0;
			when "01011" =>
				dest <= 0;
				src <= 0;
			when "01100" =>
				dest <= 0;
				src <= 8;
			when "01101" =>
				dest <= 0;
				src <= 0;
			when "01110" =>
				dest <= 0;
				src <= 0;
			when "01111" =>
				dest <= 0;
				src <= 0;
			when "10000" =>
				dest <= 0;
				src <= 0;
			when "10001" =>
				dest <= 3;
				src <= 5;
			when "10010" =>
				dest <= 0;
				src <= 0;
			when "10011" =>
				dest <= 6;
				src <= 7;
			when "10100" =>
				dest <= 0;
				src <= 0;
			when "10101" =>
				dest <= 0;
				src <= 0;
			when "10110" =>
				dest <= 0;
				src <= 4;
			when "10111" =>
				dest <= 0;
				src <= 0;
			when "11000" =>
				dest <= 1;
				src <= 2;
			when "11001" =>
				dest <= 0;
				src <= 0;
			when "11010" =>
				dest <= 0;
				src <= 3;
			when "11011" =>
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

			when "00000" =>
				dest <= 1;
				src <= 1;
			when "00001" =>
				dest <= 1;
				src <= 1;
			when "00010" =>
				dest <= 1;
				src <= 1;
			when "00011" =>
				dest <= 1;
				src <= 3;
			when "00100" =>
				dest <= 1;
				src <= 1;
			when "00101" =>
				dest <= 5;
				src <= 7;
			when "00110" =>
				dest <= 1;
				src <= 1;
			when "00111" =>
				dest <= 1;
				src <= 1;
			when "01000" =>
				dest <= 1;
				src <= 1;
			when "01001" =>
				dest <= 1;
				src <= 1;
			when "01010" =>
				dest <= 8;
				src <= 1;
			when "01011" =>
				dest <= 1;
				src <= 1;
			when "01100" =>
				dest <= 6;
				src <= 1;
			when "01101" =>
				dest <= 1;
				src <= 1;
			when "01110" =>
				dest <= 1;
				src <= 6;
			when "01111" =>
				dest <= 1;
				src <= 1;
			when "10000" =>
				dest <= 1;
				src <= 1;
			when "10001" =>
				dest <= 4;
				src <= 1;
			when "10010" =>
				dest <= 3;
				src <= 1;
			when "10011" =>
				dest <= 7;
				src <= 8;
			when "10100" =>
				dest <= 1;
				src <= 1;
			when "10101" =>
				dest <= 1;
				src <= 1;
			when "10110" =>
				dest <= 1;
				src <= 5;
			when "10111" =>
				dest <= 1;
				src <= 1;
			when "11000" =>
				dest <= 2;
				src <= 1;
			when "11001" =>
				dest <= 1;
				src <= 0;
			when "11010" =>
				dest <= 0;
				src <= 4;
			when "11011" =>
				dest <= 1;
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

			when "00000" =>
				dest <= 2;
				src <= 2;
			when "00001" =>
				dest <= 2;
				src <= 2;
			when "00010" =>
				dest <= 6;
				src <= 2;
			when "00011" =>
				dest <= 2;
				src <= 4;
			when "00100" =>
				dest <= 2;
				src <= 2;
			when "00101" =>
				dest <= 2;
				src <= 8;
			when "00110" =>
				dest <= 2;
				src <= 2;
			when "00111" =>
				dest <= 3;
				src <= 2;
			when "01000" =>
				dest <= 2;
				src <= 6;
			when "01001" =>
				dest <= 2;
				src <= 2;
			when "01010" =>
				dest <= 2;
				src <= 2;
			when "01011" =>
				dest <= 2;
				src <= 0;
			when "01100" =>
				dest <= 7;
				src <= 2;
			when "01101" =>
				dest <= 2;
				src <= 2;
			when "01110" =>
				dest <= 2;
				src <= 7;
			when "01111" =>
				dest <= 2;
				src <= 2;
			when "10000" =>
				dest <= 2;
				src <= 3;
			when "10001" =>
				dest <= 5;
				src <= 2;
			when "10010" =>
				dest <= 4;
				src <= 2;
			when "10011" =>
				dest <= 8;
				src <= 2;
			when "10100" =>
				dest <= 2;
				src <= 2;
			when "10101" =>
				dest <= 2;
				src <= 2;
			when "10110" =>
				dest <= 0;
				src <= 2;
			when "10111" =>
				dest <= 2;
				src <= 2;
			when "11000" =>
				dest <= 2;
				src <= 2;
			when "11001" =>
				dest <= 2;
				src <= 1;
			when "11010" =>
				dest <= 1;
				src <= 5;
			when "11011" =>
				dest <= 2;
				src <= 2;
			when others =>
				dest <= 2;
				src <= 2;

		end case;
	end process;

	end generate NI_NUM2;

	NI_NUM3 : if NI_NUM = 3 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 3;
				src <= 3;
			when "00001" =>
				dest <= 1;
				src <= 3;
			when "00010" =>
				dest <= 3;
				src <= 3;
			when "00011" =>
				dest <= 3;
				src <= 3;
			when "00100" =>
				dest <= 3;
				src <= 3;
			when "00101" =>
				dest <= 7;
				src <= 3;
			when "00110" =>
				dest <= 8;
				src <= 3;
			when "00111" =>
				dest <= 3;
				src <= 3;
			when "01000" =>
				dest <= 3;
				src <= 3;
			when "01001" =>
				dest <= 5;
				src <= 3;
			when "01010" =>
				dest <= 3;
				src <= 2;
			when "01011" =>
				dest <= 3;
				src <= 3;
			when "01100" =>
				dest <= 3;
				src <= 3;
			when "01101" =>
				dest <= 2;
				src <= 3;
			when "01110" =>
				dest <= 3;
				src <= 3;
			when "01111" =>
				dest <= 3;
				src <= 3;
			when "10000" =>
				dest <= 3;
				src <= 3;
			when "10001" =>
				dest <= 6;
				src <= 8;
			when "10010" =>
				dest <= 3;
				src <= 0;
			when "10011" =>
				dest <= 3;
				src <= 3;
			when "10100" =>
				dest <= 3;
				src <= 1;
			when "10101" =>
				dest <= 3;
				src <= 3;
			when "10110" =>
				dest <= 3;
				src <= 7;
			when "10111" =>
				dest <= 3;
				src <= 3;
			when "11000" =>
				dest <= 4;
				src <= 5;
			when "11001" =>
				dest <= 0;
				src <= 3;
			when "11010" =>
				dest <= 3;
				src <= 6;
			when "11011" =>
				dest <= 3;
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

			when "00000" =>
				dest <= 4;
				src <= 4;
			when "00001" =>
				dest <= 2;
				src <= 4;
			when "00010" =>
				dest <= 4;
				src <= 4;
			when "00011" =>
				dest <= 4;
				src <= 6;
			when "00100" =>
				dest <= 4;
				src <= 4;
			when "00101" =>
				dest <= 8;
				src <= 4;
			when "00110" =>
				dest <= 4;
				src <= 4;
			when "00111" =>
				dest <= 4;
				src <= 0;
			when "01000" =>
				dest <= 4;
				src <= 4;
			when "01001" =>
				dest <= 4;
				src <= 4;
			when "01010" =>
				dest <= 4;
				src <= 4;
			when "01011" =>
				dest <= 4;
				src <= 4;
			when "01100" =>
				dest <= 4;
				src <= 4;
			when "01101" =>
				dest <= 4;
				src <= 4;
			when "01110" =>
				dest <= 4;
				src <= 4;
			when "01111" =>
				dest <= 4;
				src <= 4;
			when "10000" =>
				dest <= 4;
				src <= 4;
			when "10001" =>
				dest <= 7;
				src <= 4;
			when "10010" =>
				dest <= 6;
				src <= 1;
			when "10011" =>
				dest <= 4;
				src <= 4;
			when "10100" =>
				dest <= 0;
				src <= 2;
			when "10101" =>
				dest <= 4;
				src <= 4;
			when "10110" =>
				dest <= 4;
				src <= 8;
			when "10111" =>
				dest <= 4;
				src <= 4;
			when "11000" =>
				dest <= 5;
				src <= 4;
			when "11001" =>
				dest <= 1;
				src <= 3;
			when "11010" =>
				dest <= 3;
				src <= 7;
			when "11011" =>
				dest <= 4;
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

			when "00000" =>
				dest <= 5;
				src <= 5;
			when "00001" =>
				dest <= 5;
				src <= 5;
			when "00010" =>
				dest <= 5;
				src <= 5;
			when "00011" =>
				dest <= 5;
				src <= 7;
			when "00100" =>
				dest <= 5;
				src <= 5;
			when "00101" =>
				dest <= 5;
				src <= 5;
			when "00110" =>
				dest <= 5;
				src <= 5;
			when "00111" =>
				dest <= 6;
				src <= 1;
			when "01000" =>
				dest <= 5;
				src <= 5;
			when "01001" =>
				dest <= 5;
				src <= 0;
			when "01010" =>
				dest <= 5;
				src <= 5;
			when "01011" =>
				dest <= 5;
				src <= 3;
			when "01100" =>
				dest <= 5;
				src <= 5;
			when "01101" =>
				dest <= 5;
				src <= 5;
			when "01110" =>
				dest <= 0;
				src <= 5;
			when "01111" =>
				dest <= 5;
				src <= 5;
			when "10000" =>
				dest <= 5;
				src <= 6;
			when "10001" =>
				dest <= 8;
				src <= 5;
			when "10010" =>
				dest <= 7;
				src <= 2;
			when "10011" =>
				dest <= 5;
				src <= 5;
			when "10100" =>
				dest <= 1;
				src <= 5;
			when "10101" =>
				dest <= 5;
				src <= 5;
			when "10110" =>
				dest <= 3;
				src <= 5;
			when "10111" =>
				dest <= 5;
				src <= 5;
			when "11000" =>
				dest <= 5;
				src <= 5;
			when "11001" =>
				dest <= 2;
				src <= 4;
			when "11010" =>
				dest <= 4;
				src <= 8;
			when "11011" =>
				dest <= 5;
				src <= 5;
			when others =>
				dest <= 5;
				src <= 5;

		end case;
	end process;

	end generate NI_NUM5;

	NI_NUM6 : if NI_NUM = 6 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 6;
				src <= 6;
			when "00001" =>
				dest <= 4;
				src <= 6;
			when "00010" =>
				dest <= 6;
				src <= 6;
			when "00011" =>
				dest <= 0;
				src <= 6;
			when "00100" =>
				dest <= 2;
				src <= 6;
			when "00101" =>
				dest <= 6;
				src <= 6;
			when "00110" =>
				dest <= 6;
				src <= 2;
			when "00111" =>
				dest <= 6;
				src <= 6;
			when "01000" =>
				dest <= 6;
				src <= 6;
			when "01001" =>
				dest <= 8;
				src <= 6;
			when "01010" =>
				dest <= 6;
				src <= 5;
			when "01011" =>
				dest <= 1;
				src <= 6;
			when "01100" =>
				dest <= 6;
				src <= 6;
			when "01101" =>
				dest <= 5;
				src <= 6;
			when "01110" =>
				dest <= 6;
				src <= 6;
			when "01111" =>
				dest <= 6;
				src <= 1;
			when "10000" =>
				dest <= 6;
				src <= 6;
			when "10001" =>
				dest <= 6;
				src <= 6;
			when "10010" =>
				dest <= 6;
				src <= 3;
			when "10011" =>
				dest <= 6;
				src <= 6;
			when "10100" =>
				dest <= 6;
				src <= 4;
			when "10101" =>
				dest <= 6;
				src <= 0;
			when "10110" =>
				dest <= 6;
				src <= 6;
			when "10111" =>
				dest <= 6;
				src <= 6;
			when "11000" =>
				dest <= 7;
				src <= 8;
			when "11001" =>
				dest <= 3;
				src <= 6;
			when "11010" =>
				dest <= 6;
				src <= 6;
			when "11011" =>
				dest <= 6;
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

			when "00000" =>
				dest <= 7;
				src <= 7;
			when "00001" =>
				dest <= 5;
				src <= 7;
			when "00010" =>
				dest <= 7;
				src <= 7;
			when "00011" =>
				dest <= 1;
				src <= 7;
			when "00100" =>
				dest <= 7;
				src <= 7;
			when "00101" =>
				dest <= 7;
				src <= 7;
			when "00110" =>
				dest <= 7;
				src <= 7;
			when "00111" =>
				dest <= 7;
				src <= 3;
			when "01000" =>
				dest <= 7;
				src <= 7;
			when "01001" =>
				dest <= 7;
				src <= 7;
			when "01010" =>
				dest <= 7;
				src <= 7;
			when "01011" =>
				dest <= 2;
				src <= 7;
			when "01100" =>
				dest <= 7;
				src <= 7;
			when "01101" =>
				dest <= 7;
				src <= 0;
			when "01110" =>
				dest <= 7;
				src <= 7;
			when "01111" =>
				dest <= 7;
				src <= 2;
			when "10000" =>
				dest <= 0;
				src <= 7;
			when "10001" =>
				dest <= 7;
				src <= 7;
			when "10010" =>
				dest <= 7;
				src <= 4;
			when "10011" =>
				dest <= 7;
				src <= 7;
			when "10100" =>
				dest <= 3;
				src <= 5;
			when "10101" =>
				dest <= 7;
				src <= 1;
			when "10110" =>
				dest <= 7;
				src <= 7;
			when "10111" =>
				dest <= 7;
				src <= 7;
			when "11000" =>
				dest <= 8;
				src <= 7;
			when "11001" =>
				dest <= 4;
				src <= 6;
			when "11010" =>
				dest <= 6;
				src <= 7;
			when "11011" =>
				dest <= 7;
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

			when "00000" =>
				dest <= 8;
				src <= 8;
			when "00001" =>
				dest <= 8;
				src <= 8;
			when "00010" =>
				dest <= 8;
				src <= 8;
			when "00011" =>
				dest <= 2;
				src <= 8;
			when "00100" =>
				dest <= 8;
				src <= 0;
			when "00101" =>
				dest <= 8;
				src <= 8;
			when "00110" =>
				dest <= 8;
				src <= 8;
			when "00111" =>
				dest <= 8;
				src <= 4;
			when "01000" =>
				dest <= 0;
				src <= 8;
			when "01001" =>
				dest <= 8;
				src <= 3;
			when "01010" =>
				dest <= 8;
				src <= 8;
			when "01011" =>
				dest <= 8;
				src <= 6;
			when "01100" =>
				dest <= 8;
				src <= 8;
			when "01101" =>
				dest <= 8;
				src <= 1;
			when "01110" =>
				dest <= 3;
				src <= 8;
			when "01111" =>
				dest <= 8;
				src <= 8;
			when "10000" =>
				dest <= 1;
				src <= 8;
			when "10001" =>
				dest <= 8;
				src <= 8;
			when "10010" =>
				dest <= 8;
				src <= 5;
			when "10011" =>
				dest <= 8;
				src <= 8;
			when "10100" =>
				dest <= 4;
				src <= 8;
			when "10101" =>
				dest <= 8;
				src <= 2;
			when "10110" =>
				dest <= 6;
				src <= 8;
			when "10111" =>
				dest <= 8;
				src <= 8;
			when "11000" =>
				dest <= 8;
				src <= 8;
			when "11001" =>
				dest <= 5;
				src <= 7;
			when "11010" =>
				dest <= 7;
				src <= 8;
			when "11011" =>
				dest <= 8;
				src <= 8;
			when others =>
				dest <= 8;
				src <= 8;

		end case;
	end process;

	end generate NI_NUM8;

end data;
