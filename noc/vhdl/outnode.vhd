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

entity outnode is
  port(
    clk   : in std_logic;
    reset : in std_logic;
    in0   : in network_link_forward;
    in1   : in network_link_forward;
    in2   : in network_link_forward;
    in3   : in network_link_forward;

    sel     : in  integer range 0 to 3;
    reg_out : out network_link_forward
    );
end entity outnode;

architecture arc of outnode is

  signal next_q : network_link_forward;

begin

  with sel select
    next_q <= in0 when 0,
    in1           when 1,
    in2           when 2,
    in3           when others;

  -- output assignment
  Reg : process (clk, reset) is
  begin
    if reset = '1' then
      reg_out.data       <= (others => '0');
      reg_out.data_valid <= '0';
    elsif rising_edge(clk) then
      reg_out <= next_q;
    end if;
  end process Reg;

end architecture arc;

