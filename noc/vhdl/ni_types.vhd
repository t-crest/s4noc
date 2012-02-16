library ieee;
use ieee.std_logic_1164.all;

package ni_types is

  constant TILE_ADDRESS_WIDTH : integer := 8;  -- The width of the tile address signal
  constant TILE_WORD_WIDTH    : integer := 16;  -- The width of the tile data signal
  constant NETWORK_PHITS_PR_FLIT : integer := 2;  -- The number of network phits pr network flit
  constant NETWORK_PHIT_WIDTH : integer := TILE_WORD_WIDTH/NETWORK_PHITS_PR_FLIT;  -- The width of the network channel

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
    data : network_phit;                -- Data part of the forward channel.
  end record;

  type network_link_backward is record  -- Backward channel is empty for the synchronous version of the network.
    -- Signal -- Empty at the moment, no backward channel signals for the synchronous network.
    ack : std_logic;
  end record;

  function log2 (N : natural) return integer;


end ni_types;

package body ni_types is

  function log2(N : natural) return integer is
  begin
    for I in 1 to 30 loop
      if (2**I > N) then return (I-1); end if;
    end loop;  -- I
    return(30);
  end;

end ni_types;

