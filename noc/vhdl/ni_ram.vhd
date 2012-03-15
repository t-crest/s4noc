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

--
-- Network Interface for the s4noc
--


library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;
use work.leros_types.all;
use work.noc_types.all;

entity ni_ram is
  generic (
    TOTAL_NI_NUM  : natural;
    NI_NUM        : natural;
    stable_length : natural);           -- The slot table length should be
  -- modified to fit the NoC.
  port (
    router_clk    : in  std_logic;
    processor_clk : in  std_logic;
    reset         : in  std_logic;
    -- Signals to/from the router
    tile_tx_f     : out network_link_forward;
    tile_tx_b     : in  network_link_backward;
    tile_rx_f     : in  network_link_forward;
    tile_rx_b     : out network_link_backward;
    -- Signals to/from the tile
    processor_out : in  io_out_type;
    processor_in  : out io_in_type);

end ni_ram;

architecture behav of ni_ram is
  signal count : unsigned(log2(stable_length) downto 0);  -- Count to
                                                          -- describe the
                                                          -- slot number.

  signal tx_addr                                                  : tile_address;  -- Register to save address from the tile.
  signal out_tx_status, out_rx_status, in_tx_status, in_rx_status : std_logic_vector(TOTAL_NI_NUM-1 downto 0);

  signal tx_status_reg, next_tx_status_reg : std_logic_vector(TOTAL_NI_NUM-1 downto 0);  -- Status register for communicating to the tile.
  signal rx_status_reg, next_rx_status_reg : std_logic_vector(TOTAL_NI_NUM-1 downto 0);  -- Status register for communicating to the tile.
  signal tx_slot_dest, rx_slot_src         : integer range 0 to TOTAL_NI_NUM;
  signal next_rx_slot_src                  : integer range 0 to TOTAL_NI_NUM;
  signal dest_addr, src_addr               : integer range 0 to TOTAL_NI_NUM;

  signal tx_in, tx_out, rx_in, rx_out : tile_word;
  signal tx_out_reg, tx_out_mux       : tile_word;
  signal out_addr, in_addr            : integer range 0 to 2*TOTAL_NI_NUM;
  signal out_wr, in_wr, out_en, in_en : std_logic;

  signal next_tx_data_valid, next_next_tx_data_valid, reg_tx_data_valid, reg_next_tx_data_valid : std_logic;
  
begin  -- behav

-------------------------------------------------------------------------------
-- Counter for keeping track of the timeslot number
-------------------------------------------------------------------------------
  
  counter : process (processor_clk, reset)
  begin  -- process count
    if reset = '1' then                    -- asynchronous reset (active high)
--      count <= to_unsigned(1,log2(stable_length)+1);
      count <= (others => '0');
    elsif rising_edge(processor_clk) then  -- rising clock edge
      if count < stable_length-1 then
        count <= count + to_unsigned(1, 1);
      else
        count <= (others => '0');
      end if;

    end if;
  end process counter;

-------------------------------------------------------------------------------
-- Serialize/deserialize or atomize/deatomize
-------------------------------------------------------------------------------

  serdes : entity work.serdes
    generic map (
      tile_width => tile_word'length,
      ratio_clk  => NETWORK_PHITS_PR_FLIT)
    port map (
      fast_clk     => router_clk,
      slow_clk     => processor_clk,
      reset        => reset,
      serial_in    => tile_rx_f.data,
      parallel_in  => tx_out_reg,
      serial_out   => tile_tx_f.data,
      parallel_out => rx_in);


-------------------------------------------------------------------------------
-- Dual portet block ram.
-------------------------------------------------------------------------------

  dp_ram : entity work.dp_ram
    generic map (
      DATA_WIDTH => tile_word'length,
      ADDR_WIDTH => log2(TOTAL_NI_NUM)+1)
    port map (
      clk     => router_clk,
      addr1   => std_logic_vector(to_unsigned(in_addr, log2(TOTAL_NI_NUM)+1)),
      data_w1 => tx_in,
      data_r1 => rx_out,
      nwr1    => (not in_wr),
      ncs1    => not in_en,
      addr2   => std_logic_vector(to_unsigned(out_addr, log2(TOTAL_NI_NUM)+1)),
      data_w2 => rx_in,
      data_r2 => tx_out,
      nwr2    => not out_wr,
      ncs2    => not out_en);

-------------------------------------------------------------------------------
--  Router side of the block ram
-------------------------------------------------------------------------------

  out_ch : process (processor_clk, dest_addr, rx_slot_src , tx_status_reg, rx_status_reg, tile_rx_f, reg_next_tx_data_valid, tile_rx_f.data_valid, tx_out, reg_tx_data_valid)
  begin  -- process tx_ch
    out_en                  <= '0';
    out_addr                <= 0;
    out_wr                  <= '0';
    out_tx_status           <= (others => '0');
    out_rx_status           <= (others => '0');
    next_tx_data_valid      <= reg_next_tx_data_valid;
    next_next_tx_data_valid <= '0';
    if processor_clk = '1' and tx_status_reg(dest_addr) = '1' then
      out_addr                 <= dest_addr;
      out_en                   <= '1';
      out_wr                   <= '0';
      next_tx_data_valid       <= '1';
      next_next_tx_data_valid  <= '1';
      out_tx_status(dest_addr) <= '1';
    elsif processor_clk = '0' and rx_status_reg(rx_slot_src) = '0' then
      out_addr                   <= rx_slot_src + TOTAL_NI_NUM;
      out_en                     <= tile_rx_f.data_valid;
      out_wr                     <= '1';
      out_rx_status(rx_slot_src) <= tile_rx_f.data_valid;
    end if;

    if reg_tx_data_valid = '1' then
      tx_out_mux <= tx_out;
    else
      tx_out_mux <= (others => '0');
    end if;
  end process out_ch;

  out_ch_regs : process (router_clk, reset)
  begin  -- process out_ch_regs
    if reset = '1' then                 -- asynchronous reset (active high)
      tile_tx_f.data_valid   <= '0';
      reg_tx_data_valid      <= '0';
      reg_next_tx_data_valid <= '0';
      tx_out_reg             <= (others => '0');
    elsif rising_edge(router_clk) then  -- rising clock edge
      tx_out_reg             <= tx_out_mux;
      tile_tx_f.data_valid   <= reg_tx_data_valid;
      reg_tx_data_valid      <= next_tx_data_valid;
      reg_next_tx_data_valid <= next_next_tx_data_valid;
    end if;
  end process out_ch_regs;

-------------------------------------------------------------------------------
-- Processor side of the block ram
-------------------------------------------------------------------------------

  in_ch : process (processor_clk, processor_out, rx_out, processor_in, tx_status_reg, rx_status_reg)
  begin  -- process in_ch
    in_en               <= '0';
    in_addr             <= 0;
    in_wr               <= '0';
    in_tx_status        <= (others => '0');
    in_rx_status        <= (others => '0');
    processor_in.rddata <= (others => '0');
    if processor_out.rd = '1' and unsigned(processor_out.addr) < to_unsigned(TOTAL_NI_NUM, processor_out.addr'length) then
      in_addr <= to_integer(unsigned(processor_out.addr)) + TOTAL_NI_NUM;
      in_wr   <= '0';
      in_en   <= '1';

      in_rx_status(to_integer(unsigned(processor_out.addr))) <= '1';
      processor_in.rddata                                    <= rx_out;
    elsif processor_out.rd = '1' and unsigned(processor_out.addr) = to_unsigned(TOTAL_NI_NUM, processor_out.addr'length) then
      -- return status registers 
      processor_in.rddata(tx_status_reg'length-1 downto 0) <= tx_status_reg;  -- TODO fix: return the correct
                                        -- status register, depending on
                                        -- the address.
    elsif processor_out.rd = '1' and unsigned(processor_out.addr) = to_unsigned(TOTAL_NI_NUM+1, processor_out.addr'length) then
      processor_in.rddata(rx_status_reg'length-1 downto 0) <= rx_status_reg;
    end if;

    if processor_out.wr = '1' and unsigned(processor_out.addr) < to_unsigned(TOTAL_NI_NUM, processor_out.addr'length)
      and tx_status_reg(to_integer(unsigned(processor_out.addr))) = '0' then
      in_addr <= to_integer(unsigned(processor_out.addr));
      in_wr   <= '1';
      in_en   <= '1';
      tx_in   <= processor_out.wrdata;

      in_tx_status(to_integer(unsigned(processor_out.addr))) <= '1';
    else
      tx_in <= (others => '0');
    end if;
    
  end process in_ch;

-------------------------------------------------------------------------------
-- Control logic & update of the status register
-------------------------------------------------------------------------------

  control : process (tx_status_reg, rx_status_reg, in_tx_status, out_tx_status, in_rx_status, out_rx_status)
  begin  -- process control
    for i in 0 to TOTAL_NI_NUM-1 loop
      if in_tx_status(i) = '0' and out_tx_status(i) = '0' then
        next_tx_status_reg(i) <= tx_status_reg(i);
      elsif out_tx_status(i) = '1' then
        next_tx_status_reg(i) <= '0';
      elsif in_tx_status(i) = '1' then
        next_tx_status_reg(i) <= '1';
      end if;

      if in_rx_status(i) = '0' and out_rx_status(i) = '0' then
        next_rx_status_reg(i) <= rx_status_reg(i);
      elsif out_rx_status(i) = '1' then
        next_rx_status_reg(i) <= '1';
      elsif in_rx_status(i) = '1' then
        next_rx_status_reg(i) <= '0';
      end if;
      
    end loop;  -- i

    next_rx_status_reg(NI_NUM) <=  '1';
    next_tx_status_reg(NI_NUM) <=  '0';
    
  end process control;

  status_register : process (router_clk, reset)
  begin  -- process status_register
    if reset = '1' then                 -- asynchronous reset (active high)
      tx_status_reg <= (others => '0');
      rx_status_reg <= (others => '0');
    elsif rising_edge(router_clk) then  -- rising clock edge
      tx_status_reg <= next_tx_status_reg;
      rx_status_reg <= next_rx_status_reg;
    end if;
  end process status_register;

-------------------------------------------------------------------------------
-- Slot tables and registers.
-------------------------------------------------------------------------------

  ni_ST : entity work.ni_ST
    generic map (
      NI_NUM => NI_NUM)
    port map (
      count => count,
      dest  => dest_addr,
      src   => src_addr);

  slot_regs : process (processor_clk, reset)
  begin  -- process slot_regs
    if reset = '1' then                    -- asynchronous reset (active high)
--      tx_slot_dest <= 0;
      rx_slot_src      <= 0;
      next_rx_slot_src <= 0;
    elsif rising_edge(processor_clk) then  -- rising clock edge
--      tx_slot_dest <= dest_addr;
      rx_slot_src      <= next_rx_slot_src;
      next_rx_slot_src <= src_addr;
    end if;
  end process slot_regs;

end behav;
