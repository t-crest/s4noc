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
		dest	: out integer range 0 to 25;
		src	: out integer range 0 to 25
		);
end ni_ST;

architecture data of ni_ST is
begin -- data

	NI_NUM0 : if NI_NUM = 0 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 12;
				src <= 0;
			when "00001" =>
				dest <= 18;
				src <= 0;
			when "00010" =>
				dest <= 5;
				src <= 0;
			when "00011" =>
				dest <= 13;
				src <= 20;
			when "00100" =>
				dest <= 17;
				src <= 18;
			when "00101" =>
				dest <= 20;
				src <= 12;
			when "00110" =>
				dest <= 7;
				src <= 5;
			when "00111" =>
				dest <= 8;
				src <= 17;
			when "01000" =>
				dest <= 11;
				src <= 13;
			when "01001" =>
				dest <= 23;
				src <= 23;
			when "01010" =>
				dest <= 14;
				src <= 22;
			when "01011" =>
				dest <= 16;
				src <= 19;
			when "01100" =>
				dest <= 22;
				src <= 7;
			when "01101" =>
				dest <= 0;
				src <= 16;
			when "01110" =>
				dest <= 6;
				src <= 14;
			when "01111" =>
				dest <= 19;
				src <= 8;
			when "10000" =>
				dest <= 1;
				src <= 24;
			when "10001" =>
				dest <= 9;
				src <= 4;
			when "10010" =>
				dest <= 10;
				src <= 11;
			when "10011" =>
				dest <= 21;
				src <= 21;
			when "10100" =>
				dest <= 2;
				src <= 15;
			when "10101" =>
				dest <= 24;
				src <= 9;
			when "10110" =>
				dest <= 15;
				src <= 3;
			when "10111" =>
				dest <= 3;
				src <= 6;
			when "11000" =>
				dest <= 0;
				src <= 10;
			when "11001" =>
				dest <= 4;
				src <= 2;
			when "11010" =>
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
				dest <= 13;
				src <= 1;
			when "00001" =>
				dest <= 19;
				src <= 1;
			when "00010" =>
				dest <= 6;
				src <= 1;
			when "00011" =>
				dest <= 14;
				src <= 21;
			when "00100" =>
				dest <= 18;
				src <= 19;
			when "00101" =>
				dest <= 21;
				src <= 13;
			when "00110" =>
				dest <= 8;
				src <= 6;
			when "00111" =>
				dest <= 9;
				src <= 18;
			when "01000" =>
				dest <= 12;
				src <= 14;
			when "01001" =>
				dest <= 24;
				src <= 24;
			when "01010" =>
				dest <= 10;
				src <= 23;
			when "01011" =>
				dest <= 17;
				src <= 15;
			when "01100" =>
				dest <= 23;
				src <= 8;
			when "01101" =>
				dest <= 1;
				src <= 17;
			when "01110" =>
				dest <= 7;
				src <= 10;
			when "01111" =>
				dest <= 15;
				src <= 9;
			when "10000" =>
				dest <= 2;
				src <= 20;
			when "10001" =>
				dest <= 5;
				src <= 0;
			when "10010" =>
				dest <= 11;
				src <= 12;
			when "10011" =>
				dest <= 22;
				src <= 22;
			when "10100" =>
				dest <= 3;
				src <= 16;
			when "10101" =>
				dest <= 20;
				src <= 5;
			when "10110" =>
				dest <= 16;
				src <= 4;
			when "10111" =>
				dest <= 4;
				src <= 7;
			when "11000" =>
				dest <= 1;
				src <= 11;
			when "11001" =>
				dest <= 0;
				src <= 3;
			when "11010" =>
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
				dest <= 14;
				src <= 2;
			when "00001" =>
				dest <= 15;
				src <= 2;
			when "00010" =>
				dest <= 7;
				src <= 2;
			when "00011" =>
				dest <= 10;
				src <= 22;
			when "00100" =>
				dest <= 19;
				src <= 15;
			when "00101" =>
				dest <= 22;
				src <= 14;
			when "00110" =>
				dest <= 9;
				src <= 7;
			when "00111" =>
				dest <= 5;
				src <= 19;
			when "01000" =>
				dest <= 13;
				src <= 10;
			when "01001" =>
				dest <= 20;
				src <= 20;
			when "01010" =>
				dest <= 11;
				src <= 24;
			when "01011" =>
				dest <= 18;
				src <= 16;
			when "01100" =>
				dest <= 24;
				src <= 9;
			when "01101" =>
				dest <= 2;
				src <= 18;
			when "01110" =>
				dest <= 8;
				src <= 11;
			when "01111" =>
				dest <= 16;
				src <= 5;
			when "10000" =>
				dest <= 3;
				src <= 21;
			when "10001" =>
				dest <= 6;
				src <= 1;
			when "10010" =>
				dest <= 12;
				src <= 13;
			when "10011" =>
				dest <= 23;
				src <= 23;
			when "10100" =>
				dest <= 4;
				src <= 17;
			when "10101" =>
				dest <= 21;
				src <= 6;
			when "10110" =>
				dest <= 17;
				src <= 0;
			when "10111" =>
				dest <= 0;
				src <= 8;
			when "11000" =>
				dest <= 2;
				src <= 12;
			when "11001" =>
				dest <= 1;
				src <= 4;
			when "11010" =>
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

			when "00000" =>
				dest <= 10;
				src <= 3;
			when "00001" =>
				dest <= 16;
				src <= 3;
			when "00010" =>
				dest <= 8;
				src <= 3;
			when "00011" =>
				dest <= 11;
				src <= 23;
			when "00100" =>
				dest <= 15;
				src <= 16;
			when "00101" =>
				dest <= 23;
				src <= 10;
			when "00110" =>
				dest <= 5;
				src <= 8;
			when "00111" =>
				dest <= 6;
				src <= 15;
			when "01000" =>
				dest <= 14;
				src <= 11;
			when "01001" =>
				dest <= 21;
				src <= 21;
			when "01010" =>
				dest <= 12;
				src <= 20;
			when "01011" =>
				dest <= 19;
				src <= 17;
			when "01100" =>
				dest <= 20;
				src <= 5;
			when "01101" =>
				dest <= 3;
				src <= 19;
			when "01110" =>
				dest <= 9;
				src <= 12;
			when "01111" =>
				dest <= 17;
				src <= 6;
			when "10000" =>
				dest <= 4;
				src <= 22;
			when "10001" =>
				dest <= 7;
				src <= 2;
			when "10010" =>
				dest <= 13;
				src <= 14;
			when "10011" =>
				dest <= 24;
				src <= 24;
			when "10100" =>
				dest <= 0;
				src <= 18;
			when "10101" =>
				dest <= 22;
				src <= 7;
			when "10110" =>
				dest <= 18;
				src <= 1;
			when "10111" =>
				dest <= 1;
				src <= 9;
			when "11000" =>
				dest <= 3;
				src <= 13;
			when "11001" =>
				dest <= 2;
				src <= 0;
			when "11010" =>
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
				dest <= 11;
				src <= 4;
			when "00001" =>
				dest <= 17;
				src <= 4;
			when "00010" =>
				dest <= 9;
				src <= 4;
			when "00011" =>
				dest <= 12;
				src <= 24;
			when "00100" =>
				dest <= 16;
				src <= 17;
			when "00101" =>
				dest <= 24;
				src <= 11;
			when "00110" =>
				dest <= 6;
				src <= 9;
			when "00111" =>
				dest <= 7;
				src <= 16;
			when "01000" =>
				dest <= 10;
				src <= 12;
			when "01001" =>
				dest <= 22;
				src <= 22;
			when "01010" =>
				dest <= 13;
				src <= 21;
			when "01011" =>
				dest <= 15;
				src <= 18;
			when "01100" =>
				dest <= 21;
				src <= 6;
			when "01101" =>
				dest <= 4;
				src <= 15;
			when "01110" =>
				dest <= 5;
				src <= 13;
			when "01111" =>
				dest <= 18;
				src <= 7;
			when "10000" =>
				dest <= 0;
				src <= 23;
			when "10001" =>
				dest <= 8;
				src <= 3;
			when "10010" =>
				dest <= 14;
				src <= 10;
			when "10011" =>
				dest <= 20;
				src <= 20;
			when "10100" =>
				dest <= 1;
				src <= 19;
			when "10101" =>
				dest <= 23;
				src <= 8;
			when "10110" =>
				dest <= 19;
				src <= 2;
			when "10111" =>
				dest <= 2;
				src <= 5;
			when "11000" =>
				dest <= 4;
				src <= 14;
			when "11001" =>
				dest <= 3;
				src <= 1;
			when "11010" =>
				dest <= 4;
				src <= 0;
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
				dest <= 17;
				src <= 5;
			when "00001" =>
				dest <= 23;
				src <= 5;
			when "00010" =>
				dest <= 10;
				src <= 5;
			when "00011" =>
				dest <= 18;
				src <= 0;
			when "00100" =>
				dest <= 22;
				src <= 23;
			when "00101" =>
				dest <= 0;
				src <= 17;
			when "00110" =>
				dest <= 12;
				src <= 10;
			when "00111" =>
				dest <= 13;
				src <= 22;
			when "01000" =>
				dest <= 16;
				src <= 18;
			when "01001" =>
				dest <= 3;
				src <= 3;
			when "01010" =>
				dest <= 19;
				src <= 2;
			when "01011" =>
				dest <= 21;
				src <= 24;
			when "01100" =>
				dest <= 2;
				src <= 12;
			when "01101" =>
				dest <= 5;
				src <= 21;
			when "01110" =>
				dest <= 11;
				src <= 19;
			when "01111" =>
				dest <= 24;
				src <= 13;
			when "10000" =>
				dest <= 6;
				src <= 4;
			when "10001" =>
				dest <= 14;
				src <= 9;
			when "10010" =>
				dest <= 15;
				src <= 16;
			when "10011" =>
				dest <= 1;
				src <= 1;
			when "10100" =>
				dest <= 7;
				src <= 20;
			when "10101" =>
				dest <= 4;
				src <= 14;
			when "10110" =>
				dest <= 20;
				src <= 8;
			when "10111" =>
				dest <= 8;
				src <= 11;
			when "11000" =>
				dest <= 5;
				src <= 15;
			when "11001" =>
				dest <= 9;
				src <= 7;
			when "11010" =>
				dest <= 5;
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
				dest <= 18;
				src <= 6;
			when "00001" =>
				dest <= 24;
				src <= 6;
			when "00010" =>
				dest <= 11;
				src <= 6;
			when "00011" =>
				dest <= 19;
				src <= 1;
			when "00100" =>
				dest <= 23;
				src <= 24;
			when "00101" =>
				dest <= 1;
				src <= 18;
			when "00110" =>
				dest <= 13;
				src <= 11;
			when "00111" =>
				dest <= 14;
				src <= 23;
			when "01000" =>
				dest <= 17;
				src <= 19;
			when "01001" =>
				dest <= 4;
				src <= 4;
			when "01010" =>
				dest <= 15;
				src <= 3;
			when "01011" =>
				dest <= 22;
				src <= 20;
			when "01100" =>
				dest <= 3;
				src <= 13;
			when "01101" =>
				dest <= 6;
				src <= 22;
			when "01110" =>
				dest <= 12;
				src <= 15;
			when "01111" =>
				dest <= 20;
				src <= 14;
			when "10000" =>
				dest <= 7;
				src <= 0;
			when "10001" =>
				dest <= 10;
				src <= 5;
			when "10010" =>
				dest <= 16;
				src <= 17;
			when "10011" =>
				dest <= 2;
				src <= 2;
			when "10100" =>
				dest <= 8;
				src <= 21;
			when "10101" =>
				dest <= 0;
				src <= 10;
			when "10110" =>
				dest <= 21;
				src <= 9;
			when "10111" =>
				dest <= 9;
				src <= 12;
			when "11000" =>
				dest <= 6;
				src <= 16;
			when "11001" =>
				dest <= 5;
				src <= 8;
			when "11010" =>
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
				dest <= 19;
				src <= 7;
			when "00001" =>
				dest <= 20;
				src <= 7;
			when "00010" =>
				dest <= 12;
				src <= 7;
			when "00011" =>
				dest <= 15;
				src <= 2;
			when "00100" =>
				dest <= 24;
				src <= 20;
			when "00101" =>
				dest <= 2;
				src <= 19;
			when "00110" =>
				dest <= 14;
				src <= 12;
			when "00111" =>
				dest <= 10;
				src <= 24;
			when "01000" =>
				dest <= 18;
				src <= 15;
			when "01001" =>
				dest <= 0;
				src <= 0;
			when "01010" =>
				dest <= 16;
				src <= 4;
			when "01011" =>
				dest <= 23;
				src <= 21;
			when "01100" =>
				dest <= 4;
				src <= 14;
			when "01101" =>
				dest <= 7;
				src <= 23;
			when "01110" =>
				dest <= 13;
				src <= 16;
			when "01111" =>
				dest <= 21;
				src <= 10;
			when "10000" =>
				dest <= 8;
				src <= 1;
			when "10001" =>
				dest <= 11;
				src <= 6;
			when "10010" =>
				dest <= 17;
				src <= 18;
			when "10011" =>
				dest <= 3;
				src <= 3;
			when "10100" =>
				dest <= 9;
				src <= 22;
			when "10101" =>
				dest <= 1;
				src <= 11;
			when "10110" =>
				dest <= 22;
				src <= 5;
			when "10111" =>
				dest <= 5;
				src <= 13;
			when "11000" =>
				dest <= 7;
				src <= 17;
			when "11001" =>
				dest <= 6;
				src <= 9;
			when "11010" =>
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
				dest <= 15;
				src <= 8;
			when "00001" =>
				dest <= 21;
				src <= 8;
			when "00010" =>
				dest <= 13;
				src <= 8;
			when "00011" =>
				dest <= 16;
				src <= 3;
			when "00100" =>
				dest <= 20;
				src <= 21;
			when "00101" =>
				dest <= 3;
				src <= 15;
			when "00110" =>
				dest <= 10;
				src <= 13;
			when "00111" =>
				dest <= 11;
				src <= 20;
			when "01000" =>
				dest <= 19;
				src <= 16;
			when "01001" =>
				dest <= 1;
				src <= 1;
			when "01010" =>
				dest <= 17;
				src <= 0;
			when "01011" =>
				dest <= 24;
				src <= 22;
			when "01100" =>
				dest <= 0;
				src <= 10;
			when "01101" =>
				dest <= 8;
				src <= 24;
			when "01110" =>
				dest <= 14;
				src <= 17;
			when "01111" =>
				dest <= 22;
				src <= 11;
			when "10000" =>
				dest <= 9;
				src <= 2;
			when "10001" =>
				dest <= 12;
				src <= 7;
			when "10010" =>
				dest <= 18;
				src <= 19;
			when "10011" =>
				dest <= 4;
				src <= 4;
			when "10100" =>
				dest <= 5;
				src <= 23;
			when "10101" =>
				dest <= 2;
				src <= 12;
			when "10110" =>
				dest <= 23;
				src <= 6;
			when "10111" =>
				dest <= 6;
				src <= 14;
			when "11000" =>
				dest <= 8;
				src <= 18;
			when "11001" =>
				dest <= 7;
				src <= 5;
			when "11010" =>
				dest <= 8;
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
				dest <= 16;
				src <= 9;
			when "00001" =>
				dest <= 22;
				src <= 9;
			when "00010" =>
				dest <= 14;
				src <= 9;
			when "00011" =>
				dest <= 17;
				src <= 4;
			when "00100" =>
				dest <= 21;
				src <= 22;
			when "00101" =>
				dest <= 4;
				src <= 16;
			when "00110" =>
				dest <= 11;
				src <= 14;
			when "00111" =>
				dest <= 12;
				src <= 21;
			when "01000" =>
				dest <= 15;
				src <= 17;
			when "01001" =>
				dest <= 2;
				src <= 2;
			when "01010" =>
				dest <= 18;
				src <= 1;
			when "01011" =>
				dest <= 20;
				src <= 23;
			when "01100" =>
				dest <= 1;
				src <= 11;
			when "01101" =>
				dest <= 9;
				src <= 20;
			when "01110" =>
				dest <= 10;
				src <= 18;
			when "01111" =>
				dest <= 23;
				src <= 12;
			when "10000" =>
				dest <= 5;
				src <= 3;
			when "10001" =>
				dest <= 13;
				src <= 8;
			when "10010" =>
				dest <= 19;
				src <= 15;
			when "10011" =>
				dest <= 0;
				src <= 0;
			when "10100" =>
				dest <= 6;
				src <= 24;
			when "10101" =>
				dest <= 3;
				src <= 13;
			when "10110" =>
				dest <= 24;
				src <= 7;
			when "10111" =>
				dest <= 7;
				src <= 10;
			when "11000" =>
				dest <= 9;
				src <= 19;
			when "11001" =>
				dest <= 8;
				src <= 6;
			when "11010" =>
				dest <= 9;
				src <= 5;
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
				dest <= 22;
				src <= 10;
			when "00001" =>
				dest <= 3;
				src <= 10;
			when "00010" =>
				dest <= 15;
				src <= 10;
			when "00011" =>
				dest <= 23;
				src <= 5;
			when "00100" =>
				dest <= 2;
				src <= 3;
			when "00101" =>
				dest <= 5;
				src <= 22;
			when "00110" =>
				dest <= 17;
				src <= 15;
			when "00111" =>
				dest <= 18;
				src <= 2;
			when "01000" =>
				dest <= 21;
				src <= 23;
			when "01001" =>
				dest <= 8;
				src <= 8;
			when "01010" =>
				dest <= 24;
				src <= 7;
			when "01011" =>
				dest <= 1;
				src <= 4;
			when "01100" =>
				dest <= 7;
				src <= 17;
			when "01101" =>
				dest <= 10;
				src <= 1;
			when "01110" =>
				dest <= 16;
				src <= 24;
			when "01111" =>
				dest <= 4;
				src <= 18;
			when "10000" =>
				dest <= 11;
				src <= 9;
			when "10001" =>
				dest <= 19;
				src <= 14;
			when "10010" =>
				dest <= 20;
				src <= 21;
			when "10011" =>
				dest <= 6;
				src <= 6;
			when "10100" =>
				dest <= 12;
				src <= 0;
			when "10101" =>
				dest <= 9;
				src <= 19;
			when "10110" =>
				dest <= 0;
				src <= 13;
			when "10111" =>
				dest <= 13;
				src <= 16;
			when "11000" =>
				dest <= 10;
				src <= 20;
			when "11001" =>
				dest <= 14;
				src <= 12;
			when "11010" =>
				dest <= 10;
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
				dest <= 23;
				src <= 11;
			when "00001" =>
				dest <= 4;
				src <= 11;
			when "00010" =>
				dest <= 16;
				src <= 11;
			when "00011" =>
				dest <= 24;
				src <= 6;
			when "00100" =>
				dest <= 3;
				src <= 4;
			when "00101" =>
				dest <= 6;
				src <= 23;
			when "00110" =>
				dest <= 18;
				src <= 16;
			when "00111" =>
				dest <= 19;
				src <= 3;
			when "01000" =>
				dest <= 22;
				src <= 24;
			when "01001" =>
				dest <= 9;
				src <= 9;
			when "01010" =>
				dest <= 20;
				src <= 8;
			when "01011" =>
				dest <= 2;
				src <= 0;
			when "01100" =>
				dest <= 8;
				src <= 18;
			when "01101" =>
				dest <= 11;
				src <= 2;
			when "01110" =>
				dest <= 17;
				src <= 20;
			when "01111" =>
				dest <= 0;
				src <= 19;
			when "10000" =>
				dest <= 12;
				src <= 5;
			when "10001" =>
				dest <= 15;
				src <= 10;
			when "10010" =>
				dest <= 21;
				src <= 22;
			when "10011" =>
				dest <= 7;
				src <= 7;
			when "10100" =>
				dest <= 13;
				src <= 1;
			when "10101" =>
				dest <= 5;
				src <= 15;
			when "10110" =>
				dest <= 1;
				src <= 14;
			when "10111" =>
				dest <= 14;
				src <= 17;
			when "11000" =>
				dest <= 11;
				src <= 21;
			when "11001" =>
				dest <= 10;
				src <= 13;
			when "11010" =>
				dest <= 11;
				src <= 12;
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
				dest <= 24;
				src <= 12;
			when "00001" =>
				dest <= 0;
				src <= 12;
			when "00010" =>
				dest <= 17;
				src <= 12;
			when "00011" =>
				dest <= 20;
				src <= 7;
			when "00100" =>
				dest <= 4;
				src <= 0;
			when "00101" =>
				dest <= 7;
				src <= 24;
			when "00110" =>
				dest <= 19;
				src <= 17;
			when "00111" =>
				dest <= 15;
				src <= 4;
			when "01000" =>
				dest <= 23;
				src <= 20;
			when "01001" =>
				dest <= 5;
				src <= 5;
			when "01010" =>
				dest <= 21;
				src <= 9;
			when "01011" =>
				dest <= 3;
				src <= 1;
			when "01100" =>
				dest <= 9;
				src <= 19;
			when "01101" =>
				dest <= 12;
				src <= 3;
			when "01110" =>
				dest <= 18;
				src <= 21;
			when "01111" =>
				dest <= 1;
				src <= 15;
			when "10000" =>
				dest <= 13;
				src <= 6;
			when "10001" =>
				dest <= 16;
				src <= 11;
			when "10010" =>
				dest <= 22;
				src <= 23;
			when "10011" =>
				dest <= 8;
				src <= 8;
			when "10100" =>
				dest <= 14;
				src <= 2;
			when "10101" =>
				dest <= 6;
				src <= 16;
			when "10110" =>
				dest <= 2;
				src <= 10;
			when "10111" =>
				dest <= 10;
				src <= 18;
			when "11000" =>
				dest <= 12;
				src <= 22;
			when "11001" =>
				dest <= 11;
				src <= 14;
			when "11010" =>
				dest <= 12;
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
				dest <= 20;
				src <= 13;
			when "00001" =>
				dest <= 1;
				src <= 13;
			when "00010" =>
				dest <= 18;
				src <= 13;
			when "00011" =>
				dest <= 21;
				src <= 8;
			when "00100" =>
				dest <= 0;
				src <= 1;
			when "00101" =>
				dest <= 8;
				src <= 20;
			when "00110" =>
				dest <= 15;
				src <= 18;
			when "00111" =>
				dest <= 16;
				src <= 0;
			when "01000" =>
				dest <= 24;
				src <= 21;
			when "01001" =>
				dest <= 6;
				src <= 6;
			when "01010" =>
				dest <= 22;
				src <= 5;
			when "01011" =>
				dest <= 4;
				src <= 2;
			when "01100" =>
				dest <= 5;
				src <= 15;
			when "01101" =>
				dest <= 13;
				src <= 4;
			when "01110" =>
				dest <= 19;
				src <= 22;
			when "01111" =>
				dest <= 2;
				src <= 16;
			when "10000" =>
				dest <= 14;
				src <= 7;
			when "10001" =>
				dest <= 17;
				src <= 12;
			when "10010" =>
				dest <= 23;
				src <= 24;
			when "10011" =>
				dest <= 9;
				src <= 9;
			when "10100" =>
				dest <= 10;
				src <= 3;
			when "10101" =>
				dest <= 7;
				src <= 17;
			when "10110" =>
				dest <= 3;
				src <= 11;
			when "10111" =>
				dest <= 11;
				src <= 19;
			when "11000" =>
				dest <= 13;
				src <= 23;
			when "11001" =>
				dest <= 12;
				src <= 10;
			when "11010" =>
				dest <= 13;
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
				dest <= 21;
				src <= 14;
			when "00001" =>
				dest <= 2;
				src <= 14;
			when "00010" =>
				dest <= 19;
				src <= 14;
			when "00011" =>
				dest <= 22;
				src <= 9;
			when "00100" =>
				dest <= 1;
				src <= 2;
			when "00101" =>
				dest <= 9;
				src <= 21;
			when "00110" =>
				dest <= 16;
				src <= 19;
			when "00111" =>
				dest <= 17;
				src <= 1;
			when "01000" =>
				dest <= 20;
				src <= 22;
			when "01001" =>
				dest <= 7;
				src <= 7;
			when "01010" =>
				dest <= 23;
				src <= 6;
			when "01011" =>
				dest <= 0;
				src <= 3;
			when "01100" =>
				dest <= 6;
				src <= 16;
			when "01101" =>
				dest <= 14;
				src <= 0;
			when "01110" =>
				dest <= 15;
				src <= 23;
			when "01111" =>
				dest <= 3;
				src <= 17;
			when "10000" =>
				dest <= 10;
				src <= 8;
			when "10001" =>
				dest <= 18;
				src <= 13;
			when "10010" =>
				dest <= 24;
				src <= 20;
			when "10011" =>
				dest <= 5;
				src <= 5;
			when "10100" =>
				dest <= 11;
				src <= 4;
			when "10101" =>
				dest <= 8;
				src <= 18;
			when "10110" =>
				dest <= 4;
				src <= 12;
			when "10111" =>
				dest <= 12;
				src <= 15;
			when "11000" =>
				dest <= 14;
				src <= 24;
			when "11001" =>
				dest <= 13;
				src <= 11;
			when "11010" =>
				dest <= 14;
				src <= 10;
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
				dest <= 2;
				src <= 15;
			when "00001" =>
				dest <= 8;
				src <= 15;
			when "00010" =>
				dest <= 20;
				src <= 15;
			when "00011" =>
				dest <= 3;
				src <= 10;
			when "00100" =>
				dest <= 7;
				src <= 8;
			when "00101" =>
				dest <= 10;
				src <= 2;
			when "00110" =>
				dest <= 22;
				src <= 20;
			when "00111" =>
				dest <= 23;
				src <= 7;
			when "01000" =>
				dest <= 1;
				src <= 3;
			when "01001" =>
				dest <= 13;
				src <= 13;
			when "01010" =>
				dest <= 4;
				src <= 12;
			when "01011" =>
				dest <= 6;
				src <= 9;
			when "01100" =>
				dest <= 12;
				src <= 22;
			when "01101" =>
				dest <= 15;
				src <= 6;
			when "01110" =>
				dest <= 21;
				src <= 4;
			when "01111" =>
				dest <= 9;
				src <= 23;
			when "10000" =>
				dest <= 16;
				src <= 14;
			when "10001" =>
				dest <= 24;
				src <= 19;
			when "10010" =>
				dest <= 0;
				src <= 1;
			when "10011" =>
				dest <= 11;
				src <= 11;
			when "10100" =>
				dest <= 17;
				src <= 5;
			when "10101" =>
				dest <= 14;
				src <= 24;
			when "10110" =>
				dest <= 5;
				src <= 18;
			when "10111" =>
				dest <= 18;
				src <= 21;
			when "11000" =>
				dest <= 15;
				src <= 0;
			when "11001" =>
				dest <= 19;
				src <= 17;
			when "11010" =>
				dest <= 15;
				src <= 16;
			when others =>
				dest <= 15;
				src <= 15;

		end case;
	end process;

	end generate NI_NUM15;

	NI_NUM16 : if NI_NUM = 16 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 3;
				src <= 16;
			when "00001" =>
				dest <= 9;
				src <= 16;
			when "00010" =>
				dest <= 21;
				src <= 16;
			when "00011" =>
				dest <= 4;
				src <= 11;
			when "00100" =>
				dest <= 8;
				src <= 9;
			when "00101" =>
				dest <= 11;
				src <= 3;
			when "00110" =>
				dest <= 23;
				src <= 21;
			when "00111" =>
				dest <= 24;
				src <= 8;
			when "01000" =>
				dest <= 2;
				src <= 4;
			when "01001" =>
				dest <= 14;
				src <= 14;
			when "01010" =>
				dest <= 0;
				src <= 13;
			when "01011" =>
				dest <= 7;
				src <= 5;
			when "01100" =>
				dest <= 13;
				src <= 23;
			when "01101" =>
				dest <= 16;
				src <= 7;
			when "01110" =>
				dest <= 22;
				src <= 0;
			when "01111" =>
				dest <= 5;
				src <= 24;
			when "10000" =>
				dest <= 17;
				src <= 10;
			when "10001" =>
				dest <= 20;
				src <= 15;
			when "10010" =>
				dest <= 1;
				src <= 2;
			when "10011" =>
				dest <= 12;
				src <= 12;
			when "10100" =>
				dest <= 18;
				src <= 6;
			when "10101" =>
				dest <= 10;
				src <= 20;
			when "10110" =>
				dest <= 6;
				src <= 19;
			when "10111" =>
				dest <= 19;
				src <= 22;
			when "11000" =>
				dest <= 16;
				src <= 1;
			when "11001" =>
				dest <= 15;
				src <= 18;
			when "11010" =>
				dest <= 16;
				src <= 17;
			when others =>
				dest <= 16;
				src <= 16;

		end case;
	end process;

	end generate NI_NUM16;

	NI_NUM17 : if NI_NUM = 17 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 4;
				src <= 17;
			when "00001" =>
				dest <= 5;
				src <= 17;
			when "00010" =>
				dest <= 22;
				src <= 17;
			when "00011" =>
				dest <= 0;
				src <= 12;
			when "00100" =>
				dest <= 9;
				src <= 5;
			when "00101" =>
				dest <= 12;
				src <= 4;
			when "00110" =>
				dest <= 24;
				src <= 22;
			when "00111" =>
				dest <= 20;
				src <= 9;
			when "01000" =>
				dest <= 3;
				src <= 0;
			when "01001" =>
				dest <= 10;
				src <= 10;
			when "01010" =>
				dest <= 1;
				src <= 14;
			when "01011" =>
				dest <= 8;
				src <= 6;
			when "01100" =>
				dest <= 14;
				src <= 24;
			when "01101" =>
				dest <= 17;
				src <= 8;
			when "01110" =>
				dest <= 23;
				src <= 1;
			when "01111" =>
				dest <= 6;
				src <= 20;
			when "10000" =>
				dest <= 18;
				src <= 11;
			when "10001" =>
				dest <= 21;
				src <= 16;
			when "10010" =>
				dest <= 2;
				src <= 3;
			when "10011" =>
				dest <= 13;
				src <= 13;
			when "10100" =>
				dest <= 19;
				src <= 7;
			when "10101" =>
				dest <= 11;
				src <= 21;
			when "10110" =>
				dest <= 7;
				src <= 15;
			when "10111" =>
				dest <= 15;
				src <= 23;
			when "11000" =>
				dest <= 17;
				src <= 2;
			when "11001" =>
				dest <= 16;
				src <= 19;
			when "11010" =>
				dest <= 17;
				src <= 18;
			when others =>
				dest <= 17;
				src <= 17;

		end case;
	end process;

	end generate NI_NUM17;

	NI_NUM18 : if NI_NUM = 18 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 0;
				src <= 18;
			when "00001" =>
				dest <= 6;
				src <= 18;
			when "00010" =>
				dest <= 23;
				src <= 18;
			when "00011" =>
				dest <= 1;
				src <= 13;
			when "00100" =>
				dest <= 5;
				src <= 6;
			when "00101" =>
				dest <= 13;
				src <= 0;
			when "00110" =>
				dest <= 20;
				src <= 23;
			when "00111" =>
				dest <= 21;
				src <= 5;
			when "01000" =>
				dest <= 4;
				src <= 1;
			when "01001" =>
				dest <= 11;
				src <= 11;
			when "01010" =>
				dest <= 2;
				src <= 10;
			when "01011" =>
				dest <= 9;
				src <= 7;
			when "01100" =>
				dest <= 10;
				src <= 20;
			when "01101" =>
				dest <= 18;
				src <= 9;
			when "01110" =>
				dest <= 24;
				src <= 2;
			when "01111" =>
				dest <= 7;
				src <= 21;
			when "10000" =>
				dest <= 19;
				src <= 12;
			when "10001" =>
				dest <= 22;
				src <= 17;
			when "10010" =>
				dest <= 3;
				src <= 4;
			when "10011" =>
				dest <= 14;
				src <= 14;
			when "10100" =>
				dest <= 15;
				src <= 8;
			when "10101" =>
				dest <= 12;
				src <= 22;
			when "10110" =>
				dest <= 8;
				src <= 16;
			when "10111" =>
				dest <= 16;
				src <= 24;
			when "11000" =>
				dest <= 18;
				src <= 3;
			when "11001" =>
				dest <= 17;
				src <= 15;
			when "11010" =>
				dest <= 18;
				src <= 19;
			when others =>
				dest <= 18;
				src <= 18;

		end case;
	end process;

	end generate NI_NUM18;

	NI_NUM19 : if NI_NUM = 19 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 1;
				src <= 19;
			when "00001" =>
				dest <= 7;
				src <= 19;
			when "00010" =>
				dest <= 24;
				src <= 19;
			when "00011" =>
				dest <= 2;
				src <= 14;
			when "00100" =>
				dest <= 6;
				src <= 7;
			when "00101" =>
				dest <= 14;
				src <= 1;
			when "00110" =>
				dest <= 21;
				src <= 24;
			when "00111" =>
				dest <= 22;
				src <= 6;
			when "01000" =>
				dest <= 0;
				src <= 2;
			when "01001" =>
				dest <= 12;
				src <= 12;
			when "01010" =>
				dest <= 3;
				src <= 11;
			when "01011" =>
				dest <= 5;
				src <= 8;
			when "01100" =>
				dest <= 11;
				src <= 21;
			when "01101" =>
				dest <= 19;
				src <= 5;
			when "01110" =>
				dest <= 20;
				src <= 3;
			when "01111" =>
				dest <= 8;
				src <= 22;
			when "10000" =>
				dest <= 15;
				src <= 13;
			when "10001" =>
				dest <= 23;
				src <= 18;
			when "10010" =>
				dest <= 4;
				src <= 0;
			when "10011" =>
				dest <= 10;
				src <= 10;
			when "10100" =>
				dest <= 16;
				src <= 9;
			when "10101" =>
				dest <= 13;
				src <= 23;
			when "10110" =>
				dest <= 9;
				src <= 17;
			when "10111" =>
				dest <= 17;
				src <= 20;
			when "11000" =>
				dest <= 19;
				src <= 4;
			when "11001" =>
				dest <= 18;
				src <= 16;
			when "11010" =>
				dest <= 19;
				src <= 15;
			when others =>
				dest <= 19;
				src <= 19;

		end case;
	end process;

	end generate NI_NUM19;

	NI_NUM20 : if NI_NUM = 20 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 7;
				src <= 20;
			when "00001" =>
				dest <= 13;
				src <= 20;
			when "00010" =>
				dest <= 0;
				src <= 20;
			when "00011" =>
				dest <= 8;
				src <= 15;
			when "00100" =>
				dest <= 12;
				src <= 13;
			when "00101" =>
				dest <= 15;
				src <= 7;
			when "00110" =>
				dest <= 2;
				src <= 0;
			when "00111" =>
				dest <= 3;
				src <= 12;
			when "01000" =>
				dest <= 6;
				src <= 8;
			when "01001" =>
				dest <= 18;
				src <= 18;
			when "01010" =>
				dest <= 9;
				src <= 17;
			when "01011" =>
				dest <= 11;
				src <= 14;
			when "01100" =>
				dest <= 17;
				src <= 2;
			when "01101" =>
				dest <= 20;
				src <= 11;
			when "01110" =>
				dest <= 1;
				src <= 9;
			when "01111" =>
				dest <= 14;
				src <= 3;
			when "10000" =>
				dest <= 21;
				src <= 19;
			when "10001" =>
				dest <= 4;
				src <= 24;
			when "10010" =>
				dest <= 5;
				src <= 6;
			when "10011" =>
				dest <= 16;
				src <= 16;
			when "10100" =>
				dest <= 22;
				src <= 10;
			when "10101" =>
				dest <= 19;
				src <= 4;
			when "10110" =>
				dest <= 10;
				src <= 23;
			when "10111" =>
				dest <= 23;
				src <= 1;
			when "11000" =>
				dest <= 20;
				src <= 5;
			when "11001" =>
				dest <= 24;
				src <= 22;
			when "11010" =>
				dest <= 20;
				src <= 21;
			when others =>
				dest <= 20;
				src <= 20;

		end case;
	end process;

	end generate NI_NUM20;

	NI_NUM21 : if NI_NUM = 21 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 8;
				src <= 21;
			when "00001" =>
				dest <= 14;
				src <= 21;
			when "00010" =>
				dest <= 1;
				src <= 21;
			when "00011" =>
				dest <= 9;
				src <= 16;
			when "00100" =>
				dest <= 13;
				src <= 14;
			when "00101" =>
				dest <= 16;
				src <= 8;
			when "00110" =>
				dest <= 3;
				src <= 1;
			when "00111" =>
				dest <= 4;
				src <= 13;
			when "01000" =>
				dest <= 7;
				src <= 9;
			when "01001" =>
				dest <= 19;
				src <= 19;
			when "01010" =>
				dest <= 5;
				src <= 18;
			when "01011" =>
				dest <= 12;
				src <= 10;
			when "01100" =>
				dest <= 18;
				src <= 3;
			when "01101" =>
				dest <= 21;
				src <= 12;
			when "01110" =>
				dest <= 2;
				src <= 5;
			when "01111" =>
				dest <= 10;
				src <= 4;
			when "10000" =>
				dest <= 22;
				src <= 15;
			when "10001" =>
				dest <= 0;
				src <= 20;
			when "10010" =>
				dest <= 6;
				src <= 7;
			when "10011" =>
				dest <= 17;
				src <= 17;
			when "10100" =>
				dest <= 23;
				src <= 11;
			when "10101" =>
				dest <= 15;
				src <= 0;
			when "10110" =>
				dest <= 11;
				src <= 24;
			when "10111" =>
				dest <= 24;
				src <= 2;
			when "11000" =>
				dest <= 21;
				src <= 6;
			when "11001" =>
				dest <= 20;
				src <= 23;
			when "11010" =>
				dest <= 21;
				src <= 22;
			when others =>
				dest <= 21;
				src <= 21;

		end case;
	end process;

	end generate NI_NUM21;

	NI_NUM22 : if NI_NUM = 22 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 9;
				src <= 22;
			when "00001" =>
				dest <= 10;
				src <= 22;
			when "00010" =>
				dest <= 2;
				src <= 22;
			when "00011" =>
				dest <= 5;
				src <= 17;
			when "00100" =>
				dest <= 14;
				src <= 10;
			when "00101" =>
				dest <= 17;
				src <= 9;
			when "00110" =>
				dest <= 4;
				src <= 2;
			when "00111" =>
				dest <= 0;
				src <= 14;
			when "01000" =>
				dest <= 8;
				src <= 5;
			when "01001" =>
				dest <= 15;
				src <= 15;
			when "01010" =>
				dest <= 6;
				src <= 19;
			when "01011" =>
				dest <= 13;
				src <= 11;
			when "01100" =>
				dest <= 19;
				src <= 4;
			when "01101" =>
				dest <= 22;
				src <= 13;
			when "01110" =>
				dest <= 3;
				src <= 6;
			when "01111" =>
				dest <= 11;
				src <= 0;
			when "10000" =>
				dest <= 23;
				src <= 16;
			when "10001" =>
				dest <= 1;
				src <= 21;
			when "10010" =>
				dest <= 7;
				src <= 8;
			when "10011" =>
				dest <= 18;
				src <= 18;
			when "10100" =>
				dest <= 24;
				src <= 12;
			when "10101" =>
				dest <= 16;
				src <= 1;
			when "10110" =>
				dest <= 12;
				src <= 20;
			when "10111" =>
				dest <= 20;
				src <= 3;
			when "11000" =>
				dest <= 22;
				src <= 7;
			when "11001" =>
				dest <= 21;
				src <= 24;
			when "11010" =>
				dest <= 22;
				src <= 23;
			when others =>
				dest <= 22;
				src <= 22;

		end case;
	end process;

	end generate NI_NUM22;

	NI_NUM23 : if NI_NUM = 23 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 5;
				src <= 23;
			when "00001" =>
				dest <= 11;
				src <= 23;
			when "00010" =>
				dest <= 3;
				src <= 23;
			when "00011" =>
				dest <= 6;
				src <= 18;
			when "00100" =>
				dest <= 10;
				src <= 11;
			when "00101" =>
				dest <= 18;
				src <= 5;
			when "00110" =>
				dest <= 0;
				src <= 3;
			when "00111" =>
				dest <= 1;
				src <= 10;
			when "01000" =>
				dest <= 9;
				src <= 6;
			when "01001" =>
				dest <= 16;
				src <= 16;
			when "01010" =>
				dest <= 7;
				src <= 15;
			when "01011" =>
				dest <= 14;
				src <= 12;
			when "01100" =>
				dest <= 15;
				src <= 0;
			when "01101" =>
				dest <= 23;
				src <= 14;
			when "01110" =>
				dest <= 4;
				src <= 7;
			when "01111" =>
				dest <= 12;
				src <= 1;
			when "10000" =>
				dest <= 24;
				src <= 17;
			when "10001" =>
				dest <= 2;
				src <= 22;
			when "10010" =>
				dest <= 8;
				src <= 9;
			when "10011" =>
				dest <= 19;
				src <= 19;
			when "10100" =>
				dest <= 20;
				src <= 13;
			when "10101" =>
				dest <= 17;
				src <= 2;
			when "10110" =>
				dest <= 13;
				src <= 21;
			when "10111" =>
				dest <= 21;
				src <= 4;
			when "11000" =>
				dest <= 23;
				src <= 8;
			when "11001" =>
				dest <= 22;
				src <= 20;
			when "11010" =>
				dest <= 23;
				src <= 24;
			when others =>
				dest <= 23;
				src <= 23;

		end case;
	end process;

	end generate NI_NUM23;

	NI_NUM24 : if NI_NUM = 24 generate
	process(count) begin

		case count is

			when "00000" =>
				dest <= 6;
				src <= 24;
			when "00001" =>
				dest <= 12;
				src <= 24;
			when "00010" =>
				dest <= 4;
				src <= 24;
			when "00011" =>
				dest <= 7;
				src <= 19;
			when "00100" =>
				dest <= 11;
				src <= 12;
			when "00101" =>
				dest <= 19;
				src <= 6;
			when "00110" =>
				dest <= 1;
				src <= 4;
			when "00111" =>
				dest <= 2;
				src <= 11;
			when "01000" =>
				dest <= 5;
				src <= 7;
			when "01001" =>
				dest <= 17;
				src <= 17;
			when "01010" =>
				dest <= 8;
				src <= 16;
			when "01011" =>
				dest <= 10;
				src <= 13;
			when "01100" =>
				dest <= 16;
				src <= 1;
			when "01101" =>
				dest <= 24;
				src <= 10;
			when "01110" =>
				dest <= 0;
				src <= 8;
			when "01111" =>
				dest <= 13;
				src <= 2;
			when "10000" =>
				dest <= 20;
				src <= 18;
			when "10001" =>
				dest <= 3;
				src <= 23;
			when "10010" =>
				dest <= 9;
				src <= 5;
			when "10011" =>
				dest <= 15;
				src <= 15;
			when "10100" =>
				dest <= 21;
				src <= 14;
			when "10101" =>
				dest <= 18;
				src <= 3;
			when "10110" =>
				dest <= 14;
				src <= 22;
			when "10111" =>
				dest <= 22;
				src <= 0;
			when "11000" =>
				dest <= 24;
				src <= 9;
			when "11001" =>
				dest <= 23;
				src <= 21;
			when "11010" =>
				dest <= 24;
				src <= 20;
			when others =>
				dest <= 24;
				src <= 24;

		end case;
	end process;

	end generate NI_NUM24;

end data;
