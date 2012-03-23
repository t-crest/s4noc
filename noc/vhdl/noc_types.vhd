--
--  Copyright 2012 Rasmus Bo Sørensen <rasmus@rbscloud.dk>,
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

package noc_types is

  constant TILE_ADDRESS_WIDTH    : integer := 8;  -- The width of the tile address signal
  constant TILE_WORD_WIDTH       : integer := 16;  -- The width of the tile data signal
  constant NETWORK_PHITS_PR_FLIT : integer := 2;  -- The number of network phits pr network flit
  constant NETWORK_PHIT_WIDTH    : integer := TILE_WORD_WIDTH/NETWORK_PHITS_PR_FLIT;  -- The width of the network channel

  subtype network_phit is std_logic_vector(NETWORK_PHIT_WIDTH-1 downto 0);  -- Channel data.
  subtype tile_address is std_logic_vector(TILE_ADDRESS_WIDTH-1 downto 0);  -- Tile address.
  subtype tile_word is std_logic_vector(TILE_WORD_WIDTH-1 downto 0);  -- Tile data.

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


  type select_signals is array (0 to 4) of integer range 0 to 3;

  function log2 (N : natural) return integer;


end noc_types;

package body noc_types is

  function log2(N : natural) return integer is
  begin
    for I in 1 to 64 loop
      if (2**I > N) then return I; end if;
    end loop;  -- I
    return(64);
  end;

end noc_types;

