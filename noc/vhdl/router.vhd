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
use ieee.numeric_std.all;

use work.noc_types.all;

entity router is
  port(
    clk   : in std_logic;
    reset : in std_logic;

    north_in : in network_link_forward;
    south_in : in network_link_forward;
    east_in  : in network_link_forward;
    west_in  : in network_link_forward;
    local_in : in network_link_forward;

    north_out : out network_link_forward;
    south_out : out network_link_forward;
    east_out  : out network_link_forward;
    west_out  : out network_link_forward;
    local_out : out network_link_forward
    );
end entity router;


architecture struct of router is
  signal north_in_reg : network_link_forward;
  signal south_in_reg : network_link_forward;
  signal east_in_reg  : network_link_forward;
  signal west_in_reg  : network_link_forward;
  signal local_in_reg : network_link_forward;

  signal sels, reg_sels    : select_signals;
  signal count, next_count : unsigned(log2(TDM_PERIOD) downto 0);
--    signal count, next_count : unsigned(7 downto 0);

begin
-------------------------------------------------------------------------------
-- Generating the counter for the dual clocked router
-- The following two if generate statements should be merged to one when
-- modelsim supports it. Dumb tool!
-------------------------------------------------------------------------------
  
  dualclkcounter : if DUAL_CLOCK_NOC = true generate
    
    counter : process (count)
    begin  -- process counter
      if count(log2(TDM_PERIOD) downto 0) < (TDM_PERIOD*2)-1 then
        next_count <= count + to_unsigned(1, 1);
      else
        next_count <= (others => '0');
      end if;
    end process counter;

    router_ST : entity work.router_ST
      port map (
        count => count(log2(TDM_PERIOD) downto 1),
        --    count => count(5 downto 1),
        sels  => reg_sels);

  end generate dualclkcounter;

-------------------------------------------------------------------------------
-- Generating the single clock counter for the router
-------------------------------------------------------------------------------


  singleclkcounter : if DUAL_CLOCK_NOC = false generate
    
    counter : process (count)
    begin  -- process counter
      if count < TDM_PERIOD-1 then
        next_count <= count + to_unsigned(1, 1);
      else
        next_count <= (others => '0');
      end if;
    end process counter;

    router_ST : entity work.router_ST
      port map (
        count => count(log2(TDM_PERIOD)-1 downto 0),
        --    count => count(5 downto 1),
        sels  => reg_sels);

  end generate singleclkcounter;

-------------------------------------------------------------------------------


  next_counter : process (clk, reset)
  begin  -- process next_counter
    if rising_edge(clk) then            -- rising clock edge
      if reset = '1' then
        count <= (others => '0');
      else
        count <= next_count;
      end if;
    end if;
  end process next_counter;


-------------------------------------------------------------------------------
-- Multiplexing logic
-------------------------------------------------------------------------------


  ST_reg : process (clk, reset)
  begin  -- process ST_reg
    if rising_edge(clk) then            -- rising clock edge
      if reset = '1' then
        sels <= (others => 0);
      else
        sels <= reg_sels;
      end if;
    end if;
  end process ST_reg;

  north_output : entity work.outnode
    port map (in0     => east_in_reg, in1 => south_in_reg,
              in2     => west_in_reg, in3 => local_in_reg,
              clk     => clk, reset => reset,
              sel     => sels(0),
              reg_out => north_out);

  east_output : entity work.outnode
    port map(in0     => south_in_reg, in1 => west_in_reg,
             in2     => local_in_reg, in3 => north_in_reg,
             clk     => clk, reset => reset,
             sel     => sels(1),
             reg_out => east_out);

  south_output : entity work.outnode
    port map(in0     => west_in_reg, in1 => local_in_reg,
             in2     => north_in_reg, in3 => east_in_reg,
             clk     => clk, reset => reset,
             sel     => sels(2),
             reg_out => south_out);


  west_output : entity work.outnode
    port map(in0     => local_in_reg, in1 => north_in_reg,
             in2     => east_in_reg, in3 => south_in_reg,
             clk     => clk, reset => reset,
             sel     => sels(3),
             reg_out => west_out);


  local_output : entity work.outnode
    port map(in0     => north_in_reg, in1 => east_in_reg,
             in2     => south_in_reg, in3 => west_in_reg,
             clk     => clk, reset => reset,
             sel     => sels(4),
             reg_out => local_out);


  extra_reg : if DUAL_CLOCK_NOC = true generate
    
    
    input_reg : process (clk, reset)
    begin  -- process input_reg
      if rising_edge(clk) then          -- rising clock edge
        if reset = '1' then             -- asynchronous reset (active high)
          north_in_reg.data       <= (others => '0');
          north_in_reg.data_valid <= '0';
          south_in_reg.data       <= (others => '0');
          south_in_reg.data_valid <= '0';
          east_in_reg.data        <= (others => '0');
          east_in_reg.data_valid  <= '0';
          west_in_reg.data        <= (others => '0');
          west_in_reg.data_valid  <= '0';
          local_in_reg.data       <= (others => '0');
          local_in_reg.data_valid <= '0';
        else
          north_in_reg <= north_in;
          south_in_reg <= south_in;
          east_in_reg  <= east_in;
          west_in_reg  <= west_in;
          local_in_reg <= local_in;
        end if;
      end if;
    end process input_reg;
    
  end generate extra_reg;

  no_reg : if DUAL_CLOCK_NOC = false generate
    north_in_reg <= north_in;
    south_in_reg <= south_in;
    east_in_reg  <= east_in;
    west_in_reg  <= west_in;
    local_in_reg <= local_in;
  end generate no_reg;

end architecture struct;

