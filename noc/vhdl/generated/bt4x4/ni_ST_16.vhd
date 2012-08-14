-------------------------------------------------------------
-- ni_ST_16.vhd
-- This is an auto generated file, do not edit by hand.
-------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

use work.noc_types.all;

entity ni_ST_16 is
	generic (
		NI_NUM	: natural);
	port (
		count	: in unsigned(4 downto 0);
		dest	: out integer range 0 to 15;
		src	: out integer range 0 to 15
		);
end ni_ST_16;

architecture data of ni_ST_16 is
begin -- data

	NI_NUM0 : if NI_NUM = 0 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 0;
				src <= 0;
			when "00001" =>
				dest <= 14;
				src <= 0;
			when "00010" =>
				dest <= 9;
				src <= 0;
			when "00011" =>
				dest <= 11;
				src <= 15;
			when "00100" =>
				dest <= 0;
				src <= 10;
			when "00101" =>
				dest <= 6;
				src <= 0;
			when "00110" =>
				dest <= 12;
				src <= 6;
			when "00111" =>
				dest <= 13;
				src <= 11;
			when "01000" =>
				dest <= 15;
				src <= 9;
			when "01001" =>
				dest <= 8;
				src <= 4;
			when "01010" =>
				dest <= 2;
				src <= 14;
			when "01011" =>
				dest <= 7;
				src <= 7;
			when "01100" =>
				dest <= 0;
				src <= 5;
			when "01101" =>
				dest <= 1;
				src <= 8;
			when "01110" =>
				dest <= 4;
				src <= 2;
			when "01111" =>
				dest <= 3;
				src <= 13;
			when "10000" =>
				dest <= 0;
				src <= 3;
			when "10001" =>
				dest <= 10;
				src <= 12;
			when "10010" =>
				dest <= 5;
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
				dest <= 15;
				src <= 1;
			when "00010" =>
				dest <= 10;
				src <= 1;
			when "00011" =>
				dest <= 8;
				src <= 12;
			when "00100" =>
				dest <= 1;
				src <= 11;
			when "00101" =>
				dest <= 7;
				src <= 1;
			when "00110" =>
				dest <= 13;
				src <= 7;
			when "00111" =>
				dest <= 14;
				src <= 8;
			when "01000" =>
				dest <= 12;
				src <= 10;
			when "01001" =>
				dest <= 9;
				src <= 5;
			when "01010" =>
				dest <= 3;
				src <= 15;
			when "01011" =>
				dest <= 4;
				src <= 4;
			when "01100" =>
				dest <= 1;
				src <= 6;
			when "01101" =>
				dest <= 2;
				src <= 9;
			when "01110" =>
				dest <= 5;
				src <= 3;
			when "01111" =>
				dest <= 0;
				src <= 14;
			when "10000" =>
				dest <= 1;
				src <= 0;
			when "10001" =>
				dest <= 11;
				src <= 13;
			when "10010" =>
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

			when "00000" =>
				dest <= 2;
				src <= 2;
			when "00001" =>
				dest <= 12;
				src <= 2;
			when "00010" =>
				dest <= 11;
				src <= 2;
			when "00011" =>
				dest <= 9;
				src <= 13;
			when "00100" =>
				dest <= 2;
				src <= 8;
			when "00101" =>
				dest <= 4;
				src <= 2;
			when "00110" =>
				dest <= 14;
				src <= 4;
			when "00111" =>
				dest <= 15;
				src <= 9;
			when "01000" =>
				dest <= 13;
				src <= 11;
			when "01001" =>
				dest <= 10;
				src <= 6;
			when "01010" =>
				dest <= 0;
				src <= 12;
			when "01011" =>
				dest <= 5;
				src <= 5;
			when "01100" =>
				dest <= 2;
				src <= 7;
			when "01101" =>
				dest <= 3;
				src <= 10;
			when "01110" =>
				dest <= 6;
				src <= 0;
			when "01111" =>
				dest <= 1;
				src <= 15;
			when "10000" =>
				dest <= 2;
				src <= 1;
			when "10001" =>
				dest <= 8;
				src <= 14;
			when "10010" =>
				dest <= 7;
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

			when "00000" =>
				dest <= 3;
				src <= 3;
			when "00001" =>
				dest <= 13;
				src <= 3;
			when "00010" =>
				dest <= 8;
				src <= 3;
			when "00011" =>
				dest <= 10;
				src <= 14;
			when "00100" =>
				dest <= 3;
				src <= 9;
			when "00101" =>
				dest <= 5;
				src <= 3;
			when "00110" =>
				dest <= 15;
				src <= 5;
			when "00111" =>
				dest <= 12;
				src <= 10;
			when "01000" =>
				dest <= 14;
				src <= 8;
			when "01001" =>
				dest <= 11;
				src <= 7;
			when "01010" =>
				dest <= 1;
				src <= 13;
			when "01011" =>
				dest <= 6;
				src <= 6;
			when "01100" =>
				dest <= 3;
				src <= 4;
			when "01101" =>
				dest <= 0;
				src <= 11;
			when "01110" =>
				dest <= 7;
				src <= 1;
			when "01111" =>
				dest <= 2;
				src <= 12;
			when "10000" =>
				dest <= 3;
				src <= 2;
			when "10001" =>
				dest <= 9;
				src <= 15;
			when "10010" =>
				dest <= 4;
				src <= 0;
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
				dest <= 13;
				src <= 4;
			when "00011" =>
				dest <= 15;
				src <= 3;
			when "00100" =>
				dest <= 4;
				src <= 14;
			when "00101" =>
				dest <= 10;
				src <= 4;
			when "00110" =>
				dest <= 0;
				src <= 10;
			when "00111" =>
				dest <= 1;
				src <= 15;
			when "01000" =>
				dest <= 3;
				src <= 13;
			when "01001" =>
				dest <= 12;
				src <= 8;
			when "01010" =>
				dest <= 6;
				src <= 2;
			when "01011" =>
				dest <= 11;
				src <= 11;
			when "01100" =>
				dest <= 4;
				src <= 9;
			when "01101" =>
				dest <= 5;
				src <= 12;
			when "01110" =>
				dest <= 8;
				src <= 6;
			when "01111" =>
				dest <= 7;
				src <= 1;
			when "10000" =>
				dest <= 4;
				src <= 7;
			when "10001" =>
				dest <= 14;
				src <= 0;
			when "10010" =>
				dest <= 9;
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
				dest <= 3;
				src <= 5;
			when "00010" =>
				dest <= 14;
				src <= 5;
			when "00011" =>
				dest <= 12;
				src <= 0;
			when "00100" =>
				dest <= 5;
				src <= 15;
			when "00101" =>
				dest <= 11;
				src <= 5;
			when "00110" =>
				dest <= 1;
				src <= 11;
			when "00111" =>
				dest <= 2;
				src <= 12;
			when "01000" =>
				dest <= 0;
				src <= 14;
			when "01001" =>
				dest <= 13;
				src <= 9;
			when "01010" =>
				dest <= 7;
				src <= 3;
			when "01011" =>
				dest <= 8;
				src <= 8;
			when "01100" =>
				dest <= 5;
				src <= 10;
			when "01101" =>
				dest <= 6;
				src <= 13;
			when "01110" =>
				dest <= 9;
				src <= 7;
			when "01111" =>
				dest <= 4;
				src <= 2;
			when "10000" =>
				dest <= 5;
				src <= 4;
			when "10001" =>
				dest <= 15;
				src <= 1;
			when "10010" =>
				dest <= 10;
				src <= 6;
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
				dest <= 0;
				src <= 6;
			when "00010" =>
				dest <= 15;
				src <= 6;
			when "00011" =>
				dest <= 13;
				src <= 1;
			when "00100" =>
				dest <= 6;
				src <= 12;
			when "00101" =>
				dest <= 8;
				src <= 6;
			when "00110" =>
				dest <= 2;
				src <= 8;
			when "00111" =>
				dest <= 3;
				src <= 13;
			when "01000" =>
				dest <= 1;
				src <= 15;
			when "01001" =>
				dest <= 14;
				src <= 10;
			when "01010" =>
				dest <= 4;
				src <= 0;
			when "01011" =>
				dest <= 9;
				src <= 9;
			when "01100" =>
				dest <= 6;
				src <= 11;
			when "01101" =>
				dest <= 7;
				src <= 14;
			when "01110" =>
				dest <= 10;
				src <= 4;
			when "01111" =>
				dest <= 5;
				src <= 3;
			when "10000" =>
				dest <= 6;
				src <= 5;
			when "10001" =>
				dest <= 12;
				src <= 2;
			when "10010" =>
				dest <= 11;
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
				dest <= 1;
				src <= 7;
			when "00010" =>
				dest <= 12;
				src <= 7;
			when "00011" =>
				dest <= 14;
				src <= 2;
			when "00100" =>
				dest <= 7;
				src <= 13;
			when "00101" =>
				dest <= 9;
				src <= 7;
			when "00110" =>
				dest <= 3;
				src <= 9;
			when "00111" =>
				dest <= 0;
				src <= 14;
			when "01000" =>
				dest <= 2;
				src <= 12;
			when "01001" =>
				dest <= 15;
				src <= 11;
			when "01010" =>
				dest <= 5;
				src <= 1;
			when "01011" =>
				dest <= 10;
				src <= 10;
			when "01100" =>
				dest <= 7;
				src <= 8;
			when "01101" =>
				dest <= 4;
				src <= 15;
			when "01110" =>
				dest <= 11;
				src <= 5;
			when "01111" =>
				dest <= 6;
				src <= 0;
			when "10000" =>
				dest <= 7;
				src <= 6;
			when "10001" =>
				dest <= 13;
				src <= 3;
			when "10010" =>
				dest <= 8;
				src <= 4;
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
				dest <= 6;
				src <= 8;
			when "00010" =>
				dest <= 1;
				src <= 8;
			when "00011" =>
				dest <= 3;
				src <= 7;
			when "00100" =>
				dest <= 8;
				src <= 2;
			when "00101" =>
				dest <= 14;
				src <= 8;
			when "00110" =>
				dest <= 4;
				src <= 14;
			when "00111" =>
				dest <= 5;
				src <= 3;
			when "01000" =>
				dest <= 7;
				src <= 1;
			when "01001" =>
				dest <= 0;
				src <= 12;
			when "01010" =>
				dest <= 10;
				src <= 6;
			when "01011" =>
				dest <= 15;
				src <= 15;
			when "01100" =>
				dest <= 8;
				src <= 13;
			when "01101" =>
				dest <= 9;
				src <= 0;
			when "01110" =>
				dest <= 12;
				src <= 10;
			when "01111" =>
				dest <= 11;
				src <= 5;
			when "10000" =>
				dest <= 8;
				src <= 11;
			when "10001" =>
				dest <= 2;
				src <= 4;
			when "10010" =>
				dest <= 13;
				src <= 9;
			when others =>
				dest <= 8;
				src <= 8;

		end case;
	end process;

	end generate NI_NUM8;

	NI_NUM9 : if NI_NUM = 9 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 9;
				src <= 9;
			when "00001" =>
				dest <= 7;
				src <= 9;
			when "00010" =>
				dest <= 2;
				src <= 9;
			when "00011" =>
				dest <= 0;
				src <= 4;
			when "00100" =>
				dest <= 9;
				src <= 3;
			when "00101" =>
				dest <= 15;
				src <= 9;
			when "00110" =>
				dest <= 5;
				src <= 15;
			when "00111" =>
				dest <= 6;
				src <= 0;
			when "01000" =>
				dest <= 4;
				src <= 2;
			when "01001" =>
				dest <= 1;
				src <= 13;
			when "01010" =>
				dest <= 11;
				src <= 7;
			when "01011" =>
				dest <= 12;
				src <= 12;
			when "01100" =>
				dest <= 9;
				src <= 14;
			when "01101" =>
				dest <= 10;
				src <= 1;
			when "01110" =>
				dest <= 13;
				src <= 11;
			when "01111" =>
				dest <= 8;
				src <= 6;
			when "10000" =>
				dest <= 9;
				src <= 8;
			when "10001" =>
				dest <= 3;
				src <= 5;
			when "10010" =>
				dest <= 14;
				src <= 10;
			when others =>
				dest <= 9;
				src <= 9;

		end case;
	end process;

	end generate NI_NUM9;

	NI_NUM10 : if NI_NUM = 10 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 10;
				src <= 10;
			when "00001" =>
				dest <= 4;
				src <= 10;
			when "00010" =>
				dest <= 3;
				src <= 10;
			when "00011" =>
				dest <= 1;
				src <= 5;
			when "00100" =>
				dest <= 10;
				src <= 0;
			when "00101" =>
				dest <= 12;
				src <= 10;
			when "00110" =>
				dest <= 6;
				src <= 12;
			when "00111" =>
				dest <= 7;
				src <= 1;
			when "01000" =>
				dest <= 5;
				src <= 3;
			when "01001" =>
				dest <= 2;
				src <= 14;
			when "01010" =>
				dest <= 8;
				src <= 4;
			when "01011" =>
				dest <= 13;
				src <= 13;
			when "01100" =>
				dest <= 10;
				src <= 15;
			when "01101" =>
				dest <= 11;
				src <= 2;
			when "01110" =>
				dest <= 14;
				src <= 8;
			when "01111" =>
				dest <= 9;
				src <= 7;
			when "10000" =>
				dest <= 10;
				src <= 9;
			when "10001" =>
				dest <= 0;
				src <= 6;
			when "10010" =>
				dest <= 15;
				src <= 11;
			when others =>
				dest <= 10;
				src <= 10;

		end case;
	end process;

	end generate NI_NUM10;

	NI_NUM11 : if NI_NUM = 11 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 11;
				src <= 11;
			when "00001" =>
				dest <= 5;
				src <= 11;
			when "00010" =>
				dest <= 0;
				src <= 11;
			when "00011" =>
				dest <= 2;
				src <= 6;
			when "00100" =>
				dest <= 11;
				src <= 1;
			when "00101" =>
				dest <= 13;
				src <= 11;
			when "00110" =>
				dest <= 7;
				src <= 13;
			when "00111" =>
				dest <= 4;
				src <= 2;
			when "01000" =>
				dest <= 6;
				src <= 0;
			when "01001" =>
				dest <= 3;
				src <= 15;
			when "01010" =>
				dest <= 9;
				src <= 5;
			when "01011" =>
				dest <= 14;
				src <= 14;
			when "01100" =>
				dest <= 11;
				src <= 12;
			when "01101" =>
				dest <= 8;
				src <= 3;
			when "01110" =>
				dest <= 15;
				src <= 9;
			when "01111" =>
				dest <= 10;
				src <= 4;
			when "10000" =>
				dest <= 11;
				src <= 10;
			when "10001" =>
				dest <= 1;
				src <= 7;
			when "10010" =>
				dest <= 12;
				src <= 8;
			when others =>
				dest <= 11;
				src <= 11;

		end case;
	end process;

	end generate NI_NUM11;

	NI_NUM12 : if NI_NUM = 12 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 12;
				src <= 12;
			when "00001" =>
				dest <= 10;
				src <= 12;
			when "00010" =>
				dest <= 5;
				src <= 12;
			when "00011" =>
				dest <= 7;
				src <= 11;
			when "00100" =>
				dest <= 12;
				src <= 6;
			when "00101" =>
				dest <= 2;
				src <= 12;
			when "00110" =>
				dest <= 8;
				src <= 2;
			when "00111" =>
				dest <= 9;
				src <= 7;
			when "01000" =>
				dest <= 11;
				src <= 5;
			when "01001" =>
				dest <= 4;
				src <= 0;
			when "01010" =>
				dest <= 14;
				src <= 10;
			when "01011" =>
				dest <= 3;
				src <= 3;
			when "01100" =>
				dest <= 12;
				src <= 1;
			when "01101" =>
				dest <= 13;
				src <= 4;
			when "01110" =>
				dest <= 0;
				src <= 14;
			when "01111" =>
				dest <= 15;
				src <= 9;
			when "10000" =>
				dest <= 12;
				src <= 15;
			when "10001" =>
				dest <= 6;
				src <= 8;
			when "10010" =>
				dest <= 1;
				src <= 13;
			when others =>
				dest <= 12;
				src <= 12;

		end case;
	end process;

	end generate NI_NUM12;

	NI_NUM13 : if NI_NUM = 13 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 13;
				src <= 13;
			when "00001" =>
				dest <= 11;
				src <= 13;
			when "00010" =>
				dest <= 6;
				src <= 13;
			when "00011" =>
				dest <= 4;
				src <= 8;
			when "00100" =>
				dest <= 13;
				src <= 7;
			when "00101" =>
				dest <= 3;
				src <= 13;
			when "00110" =>
				dest <= 9;
				src <= 3;
			when "00111" =>
				dest <= 10;
				src <= 4;
			when "01000" =>
				dest <= 8;
				src <= 6;
			when "01001" =>
				dest <= 5;
				src <= 1;
			when "01010" =>
				dest <= 15;
				src <= 11;
			when "01011" =>
				dest <= 0;
				src <= 0;
			when "01100" =>
				dest <= 13;
				src <= 2;
			when "01101" =>
				dest <= 14;
				src <= 5;
			when "01110" =>
				dest <= 1;
				src <= 15;
			when "01111" =>
				dest <= 12;
				src <= 10;
			when "10000" =>
				dest <= 13;
				src <= 12;
			when "10001" =>
				dest <= 7;
				src <= 9;
			when "10010" =>
				dest <= 2;
				src <= 14;
			when others =>
				dest <= 13;
				src <= 13;

		end case;
	end process;

	end generate NI_NUM13;

	NI_NUM14 : if NI_NUM = 14 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 14;
				src <= 14;
			when "00001" =>
				dest <= 8;
				src <= 14;
			when "00010" =>
				dest <= 7;
				src <= 14;
			when "00011" =>
				dest <= 5;
				src <= 9;
			when "00100" =>
				dest <= 14;
				src <= 4;
			when "00101" =>
				dest <= 0;
				src <= 14;
			when "00110" =>
				dest <= 10;
				src <= 0;
			when "00111" =>
				dest <= 11;
				src <= 5;
			when "01000" =>
				dest <= 9;
				src <= 7;
			when "01001" =>
				dest <= 6;
				src <= 2;
			when "01010" =>
				dest <= 12;
				src <= 8;
			when "01011" =>
				dest <= 1;
				src <= 1;
			when "01100" =>
				dest <= 14;
				src <= 3;
			when "01101" =>
				dest <= 15;
				src <= 6;
			when "01110" =>
				dest <= 2;
				src <= 12;
			when "01111" =>
				dest <= 13;
				src <= 11;
			when "10000" =>
				dest <= 14;
				src <= 13;
			when "10001" =>
				dest <= 4;
				src <= 10;
			when "10010" =>
				dest <= 3;
				src <= 15;
			when others =>
				dest <= 14;
				src <= 14;

		end case;
	end process;

	end generate NI_NUM14;

	NI_NUM15 : if NI_NUM = 15 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 15;
				src <= 15;
			when "00001" =>
				dest <= 9;
				src <= 15;
			when "00010" =>
				dest <= 4;
				src <= 15;
			when "00011" =>
				dest <= 6;
				src <= 10;
			when "00100" =>
				dest <= 15;
				src <= 5;
			when "00101" =>
				dest <= 1;
				src <= 15;
			when "00110" =>
				dest <= 11;
				src <= 1;
			when "00111" =>
				dest <= 8;
				src <= 6;
			when "01000" =>
				dest <= 10;
				src <= 4;
			when "01001" =>
				dest <= 7;
				src <= 3;
			when "01010" =>
				dest <= 13;
				src <= 9;
			when "01011" =>
				dest <= 2;
				src <= 2;
			when "01100" =>
				dest <= 15;
				src <= 0;
			when "01101" =>
				dest <= 12;
				src <= 7;
			when "01110" =>
				dest <= 3;
				src <= 13;
			when "01111" =>
				dest <= 14;
				src <= 8;
			when "10000" =>
				dest <= 15;
				src <= 14;
			when "10001" =>
				dest <= 5;
				src <= 11;
			when "10010" =>
				dest <= 0;
				src <= 12;
			when others =>
				dest <= 15;
				src <= 15;

		end case;
	end process;

	end generate NI_NUM15;

end data;
