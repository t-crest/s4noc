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
    NI_NUM : natural);
  port (
    count : in  unsigned(log2(TDM_PERIOD)-1 downto 0);
    dest  : out integer range 0 to 9;
    src   : out integer range 0 to 9
    );
end ni_ST;

architecture data of ni_ST is
begin  -- data

  st3x3 : if TOTAL_NI_NUM = 9 generate
    st : entity work.ni_ST_9
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st3x3;

  st4x4 : if TOTAL_NI_NUM = 16 generate
    st : entity work.ni_ST_16
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st4x4;

  st5x5 : if TOTAL_NI_NUM = 25 generate
    st : entity work.ni_ST_25
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st5x5;

  st6x6 : if TOTAL_NI_NUM = 36 generate
    st : entity work.ni_ST_36
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st6x6;
  
  st7x7 : if TOTAL_NI_NUM = 49 generate
    st : entity work.ni_ST_49
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st7x7;
  
  st8x8 : if TOTAL_NI_NUM = 64 generate
    st : entity work.ni_ST_64
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st8x8;
  
  st9x9 : if TOTAL_NI_NUM = 81 generate
    st : entity work.ni_ST_81
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st9x9;
  
  st10x10 : if TOTAL_NI_NUM = 100 generate
    st : entity work.ni_ST_100
      generic map (
        NI_NUM => NI_NUM)
      port map (
        count => count,
        dest  => dest,
        src   => src);
  end generate st10x10;

end data;
