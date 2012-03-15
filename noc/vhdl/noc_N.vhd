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
use ieee.numeric_std.all;

use work.noc_types.all;

entity noc is
  -- NxN nodes
  generic (N        : natural := 8;
           WIDTH    : natural := 16;
           PERIOD_P : natural := 28
           );
  port(
    processor_clk : in std_logic;
    router_clk : in std_logic;
    reset : in std_logic;

    ser_txd : out std_logic;
    ser_rxd : in  std_logic
    --data_in  : in  std_logic_vector(WIDTH-1 downto 0);
    --data_out : out std_logic_vector(WIDTH-1 downto 0)

    );
end entity noc;

architecture struct of noc is

  --Component noc_node
  --  generic (WIDTH    : natural;
  --           PERIOD_P : natural);
  --  port (p_clk : in std_logic;
  --        n_clk : in std_logic;
  --        reset : in std_logic;

  --        north_in : in network_link_forward;
  --        south_in : in network_link_forward;
  --        east_in  : in network_link_forward;
  --        west_in  : in network_link_forward;

  --        north_out : out network_link_forward;
  --        south_out : out network_link_forward;
  --        east_out  : out network_link_forward;
  --        west_out  : out network_link_forward

  --        );
  --end component;

  type link_n is array(0 to (N - 1)) of network_link_forward;
  type link_m is array(0 to (N - 1)) of link_n;

  signal north_in  : link_m;
  signal east_in   : link_m;
  signal south_in  : link_m;
  signal west_in   : link_m;
  signal north_out : link_m;
  signal east_out  : link_m;
  signal south_out : link_m;
  signal west_out  : link_m;

  signal open_vector : network_link_forward;

begin
  -- generate connections
  nodes_m : for i in N-1 downto 0 generate
    nodes_n : for j in N-1 downto 0 generate
      output_node : if i = 0 and j = 0 generate
        node : entity work.tile
          generic map (
            UART          => true,
            TOTAL_NI_NUM  => N*N,
            NI_NUM        => i*N+j,
            stable_length => PERIOD_P)
          port map (router_clk => router_clk, processor_clk => processor_clk,
                    reset      => reset,
                    north_in   => north_in(i)(j),
                    south_in   => south_in(i)(j),
                    east_in    => east_in(i)(j),
                    west_in    => west_in(i)(j),
                    north_out  => north_out(i)(j),
                    south_out  => south_out(i)(j),
                    east_out   => east_out(i)(j),
                    west_out   => west_out(i)(j),
                    ser_txd    => ser_txd,
                    ser_rxd    => ser_rxd
                    );
      end generate output_node;

      normal_node : if i /= 0 or j /= 0 generate
        node : entity work.tile
          generic map (
            UART          => false,
            TOTAL_NI_NUM  => N*N,
            NI_NUM        => i*N+j,
            stable_length => PERIOD_P)
          port map (router_clk => router_clk, processor_clk => processor_clk,
                    reset      => reset,
                    north_in   => north_in(i)(j),
                    south_in   => south_in(i)(j),
                    east_in    => east_in(i)(j),
                    west_in    => west_in(i)(j),
                    north_out  => north_out(i)(j),
                    south_out  => south_out(i)(j),
                    east_out   => east_out(i)(j),
                    west_out   => west_out(i)(j),
                    ser_txd    => open,
                    ser_rxd    => '0'
                    );
      end generate normal_node;
    end generate nodes_n;
  end generate nodes_m;

  ----outinterface
  --north_in(0)(0) <= data_in;
  --data_out       <= north_out(0)(0);

  --interconnections    
  open_vector.data <= (others => '0');
  links_m : for i in 0 to N-1 generate
    links_n : for j in 0 to N-1 generate

      link_north_south : if (i = 0) generate
        north_in(i)(j)   <= south_out(N-1)(j);
        south_in(N-1)(j) <= north_out(i)(j);
      end generate link_north_south;
      link_west_east : if (j = 0) generate
        west_in(i)(j)   <= east_out(i)(N-1);
        east_in(i)(N-1) <= west_out(i)(j);
      end generate link_west_east;

      bottom : if (i = (N-1) and j < (N-1)) generate
        west_in(i)(j+1) <= east_out(i)(j);
        east_in(i)(j)   <= west_out(i)(j+1);
      end generate bottom;
      right : if (i < (N-1) and j = (N-1)) generate
        north_in(i+1)(j) <= south_out(i)(j);
        south_in(i)(j)   <= north_out(i+1)(j);
      end generate right;
      center : if (i < (N-1) and j < (N-1)) generate
        north_in(i+1)(j) <= south_out(i)(j);
        south_in(i)(j)   <= north_out(i+1)(j);
        west_in(i)(j+1)  <= east_out(i)(j);
        east_in(i)(j)    <= west_out(i)(j+1);
      end generate center;
      
    end generate links_n;
  end generate links_m;

end architecture struct;

