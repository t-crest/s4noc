--
--  Copyright 2012 Rasmus Bo Soerensen <rasmus@rbscloud.dk>,
--                 Technical University of Denmark, DTU Informatics. 
--  All rights reserved.
--
-- Redistribution and use in source and binary forms, with or without
-- modification, are permitted provided that the following conditions are met:
-- 
--    1. Redistributions of source code must retain the above copyright notice,
--       this list of conditions and the following disclaimer.
-- 
--    2. Redistributions in binary form must reproduce the above copyright
--       notice, this list of conditions and the following disclaimer in the
--       documentation and/or other materials provided with the distribution.
-- 
-- THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER ``AS IS'' AND ANY EXPRESS
-- OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
-- OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
-- NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
-- DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
-- (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
-- LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
-- ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
-- (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
-- THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-- 
-- The views and conclusions contained in the software and documentation are
-- those of the authors and should not be interpreted as representing official
-- policies, either expressed or implied, of the copyright holder.
--
--

library ieee;
use ieee.std_logic_1164.all;

--package generic_noc_types is
package noc_types is
-------------------------------------------------------------------------------
-- For the time when tools support VHDL-2008
-------------------------------------------------------------------------------
  --generic (
  --  ADDR_WIDTH     : positive;  -- Width of memory addresses in the tile
  --  WORD_WIDTH     : positive;          -- Width of the data words
  --  PHIT_WIDTH     : positive;
  --  TILE_CLK_FREQ  : positive;
  --  TOTAL_NI_NUM   : positive;
  --  TDM_PERIOD     : positive;
  --  DUAL_CLOCK_NOC : boolean);  -- True if the NoC should be clock at the double frequency of the processors

  constant ADDR_WIDTH     : positive := 8;
  constant WORD_WIDTH     : positive := 16;
  constant PHIT_WIDTH     : positive := 16;
  constant TILE_CLK_FREQ  : positive := 100000000;
  constant TOTAL_NI_NUM   : positive := 16;
  constant TDM_PERIOD     : positive := 19;
  constant DUAL_CLOCK_NOC : boolean  := false;

  constant NETWORK_PHITS_PR_FLIT : positive := WORD_WIDTH/PHIT_WIDTH;

  subtype network_phit is std_logic_vector(PHIT_WIDTH-1 downto 0);  -- Channel data.
  subtype tile_address is std_logic_vector(ADDR_WIDTH-1 downto 0);  -- Tile address.
  subtype tile_word is std_logic_vector(WORD_WIDTH-1 downto 0);  -- Tile data.
  subtype status_word is std_logic_vector(TOTAL_NI_NUM-1 downto 0);  -- Status word
  subtype status_int is integer range 0 to TOTAL_NI_NUM;  -- Integer used to index in status_words

--  subtype tile_flags is std_logic_vector(FLAG_SIZE-1 downto 0);  -- Read or write flags.

  type tile_out_type is record          -- Signals out of the tile
    wrdata : tile_word;                 -- The write signal from the
    -- tile
    addr   : tile_address;              -- Output address of the tile
    rd     : std_logic;                 -- Read signal of the tile
    wr     : std_logic;                 -- Write signal of the tile
  end record;

  type tile_in_type is record           -- Signals in to the tile
    rddata : tile_word;                 -- The read data to the tile
  end record;

  type network_link_forward is record  -- Channel forward record for holding the forward signals of a channel
    data       : network_phit;          -- Data part of the forward channel.
    data_valid : std_logic;
  end record;

  type network_link_backward is record  -- Backward channel is empty for the synchronous version of the network.
    -- Signal -- Empty at the moment, no backward channel signals for the synchronous network.
    ack : std_logic;
  end record;

  type ram_side is record
    ram_en   : std_logic;
    ram_addr : natural;
    ram_wr   : std_logic;
    tx_en    : std_logic;
    rx_en    : std_logic;
    tx       : tile_word;
    rx       : tile_word;
  end record;

  
--type select_signals is array (0 to 4) of integer range 0 to 3;
  type port_t is (N,S,E,W,L,D);
  type select_signals is array (port_t'left to port_t'right) of port_t;

  function log2 (N : natural) return integer;

  function sqrt (N : positive) return integer;
  
end noc_types;

package body noc_types is

  function log2(N : natural) return integer is
  begin
    for I in 1 to 64 loop
      if (2**I > N) then return I; end if;
    end loop;  -- I
    return(64);
  end;

  function sqrt(N : positive) return integer is
  begin
    for I in 1 to 32 loop
      if (I*I >= N) then return I; end if;
    end loop;  -- I
    return(-1);
  end sqrt;

end noc_types;

