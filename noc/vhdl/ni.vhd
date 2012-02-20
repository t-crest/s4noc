library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;
use work.leros_types.all;
use work.noc_types.all;

entity ni is
  generic (
    stable_length : integer := 8);      -- The slot table length.
  port (
    router_clk    : in  std_logic;
    processor_clk : in  std_logic;
    reset         : in  std_logic;
    -- Signals to/from the router
    tile_tx_f   : out network_link_forward;
    tile_tx_b   : in  network_link_backward;
    tile_rx_f   : in  network_link_forward;
    tile_rx_b   : out network_link_backward;
    -- Signals to/from the tile
    processor_out : in  io_out_type;
    processor_in  : out io_in_type);

end ni;

architecture behav of ni is
  signal count                       : unsigned(log2(stable_length)-1 downto 0);  -- Count to
                                        -- describe the
                                        -- slot number.
  signal tx_reg, tx_out              : tile_word;  -- Register to save data word from tile.
  signal tx_addr                     : tile_address;  -- Register to save address from the tile.
  signal tx_rdy                      : std_logic;  -- Signal indicating that the correct slot
  -- is reached and the tile_word is now sent.
  signal rx_reg, rx_in               : tile_word;  -- Signal representing an entire network flit.
  signal rx_clr, rx_rdy              : std_logic;  -- Signals for clearing and setting the rx_register
  signal status_reg, next_status_reg : std_logic_vector(15 downto 0);  -- Status register for communicating to the tile.
  
begin  -- behav

  counter : process (processor_clk, reset)
  begin  -- process count
    if reset = '1' then                    -- asynchronous reset (active high)
      count <= (others => '1');
    elsif rising_edge(processor_clk) then  -- rising clock edge
      count <= count + to_unsigned(1, 1);
    end if;
  end process counter;

  serdes : entity work.serdes
    generic map (
      tile_width => tile_word'length,
      ratio_clk  => NETWORK_PHITS_PR_FLIT)
    port map (
      fast_clk     => router_clk,
      slow_clk     => processor_clk,
      reset        => reset,
      serial_in    => tile_rx_f.data,
      parallel_in  => tx_out,
      serial_out   => tile_tx_f.data,
      parallel_out => rx_in);

  tx_register : process (processor_clk, reset)
  begin  -- process tx_reg
    if reset = '1' then
      tx_reg  <= (others => '0');
      tx_addr <= (others => '0');
    elsif rising_edge(processor_clk) then  -- rising clock edge
      if processor_out.wr = '1' then
        tx_reg  <= processor_out.wrdata;
        tx_addr <= processor_out.addr;
      elsif tx_rdy = '1' then
        tx_reg  <= (others => '0');
        tx_addr <= (others => '0');
      else
        tx_reg  <= tx_reg;
        tx_addr <= tx_addr;
      end if;
    end if;
  end process tx_register;

  rx_register : process (processor_clk, reset)
  begin  -- process rx_register
    if reset = '1' then
      rx_reg <= (others => '0');
    elsif rising_edge(processor_clk) then  -- rising clock edge
      if rx_rdy = '1' then
        rx_reg <= rx_in;
      elsif rx_clr = '1' then
        rx_reg <= (others => '0');
      else
        rx_reg <= rx_reg;
      end if;
    end if;
  end process rx_register;

  rx_data : process (processor_out.rd, processor_out.addr, rx_reg, status_reg)
  begin  -- process out_data
    rx_clr <= '0';
    if processor_out.rd = '1' then
      if processor_out.addr(7) = '1' then
        processor_in.rddata <= status_reg;
      else
        processor_in.rddata <= rx_reg;
        rx_clr              <= '1';
      end if;
    else
      processor_in.rddata <= (others => '0');
    end if;
  end process rx_data;

  tx_data : process (tx_rdy, tx_reg)
  begin  -- process
    if tx_rdy = '1' then
      tx_out <= tx_reg;
    else
      tx_out <= (others => '0');
    end if;
    
  end process tx_data;

  control : process (tx_rdy, rx_rdy, processor_out.wr, rx_clr, status_reg)
    variable rx_status : std_logic;
    variable rx_error  : std_logic;
    variable tx_status : std_logic;
    variable tx_error  : std_logic;
  begin  -- process control
    rx_status := status_reg(4);
    rx_error  := '0';
    tx_status := status_reg(0);
    tx_error  := '0';
    if (rx_rdy = '0' and rx_clr = '0' and rx_status = '0') or
      (rx_rdy = '0' and rx_clr = '1' and rx_status = '1') then
      rx_status := '0';
      rx_error  := '0';
    elsif (rx_rdy = '0' and rx_clr = '1' and rx_status = '0') then
      rx_status := '0';
      rx_error  := '1';
    elsif (rx_rdy = '1' and rx_clr = '1' and rx_status = '0') or
      (rx_rdy = '1' and rx_clr = '0' and rx_status = '1') then
      rx_status := '1';
      rx_error  := '1';
    elsif (rx_rdy = '0' and rx_clr = '0' and rx_status = '1') or
      (rx_rdy = '1' and rx_clr = '0' and rx_status = '0') or
      (rx_rdy = '1' and rx_clr = '1' and rx_status = '1') then
      rx_status := '1';
      rx_error  := '0';
    end if;

    if (tx_rdy = '0' and processor_out.wr = '0' and tx_status = '0') or
      (tx_rdy = '1' and processor_out.wr = '0' and tx_status = '0') or
      (tx_rdy = '1' and processor_out.wr = '0' and tx_status = '1') then
      tx_status := '0';
      tx_error  := '0';
    elsif (tx_rdy = '0' and processor_out.wr = '1' and tx_status = '1') then
      tx_status := '1';
      tx_error  := '1';
    elsif (tx_rdy = '0' and processor_out.wr = '0' and tx_status = '1') or
      (tx_rdy = '0' and processor_out.wr = '1' and tx_status = '0') or
      (tx_rdy = '1' and processor_out.wr = '1' and tx_status = '0') or
      (tx_rdy = '1' and processor_out.wr = '1' and tx_status = '1') then
      tx_status := '1';
      tx_error  := '0';
    end if;

    next_status_reg    <= (others => '0');
    next_status_reg(7) <= rx_error;
    next_status_reg(4) <= rx_status;
    next_status_reg(3) <= tx_error;
    next_status_reg(0) <= tx_status;

    if tx_error = '1' and rx_error = '1' then
      next_status_reg(15 downto 8) <= std_logic_vector(unsigned(status_reg(15 downto 8)) + to_unsigned(2, 2));
    elsif tx_error = '1' xor rx_error = '1' then
      next_status_reg(15 downto 8) <= std_logic_vector(unsigned(status_reg(15 downto 8)) + to_unsigned(1, 2));
    else
      next_status_reg(15 downto 8) <= status_reg(15 downto 8);
    end if;
    
  end process control;

  status_register : process (processor_clk, reset)
  begin  -- process status_register
    if reset = '1' then                    -- asynchronous reset (active high)
      status_reg <= (others => '0');
    elsif rising_edge(processor_clk) then  -- rising clock edge
      status_reg <= next_status_reg;
    end if;
  end process status_register;

  tx_stable : process (count, status_reg)
  begin  -- process tx_stable
--    if count = unsigned(tx_addr(7 downto 8-count'length)) then
    if std_logic_vector(count(1 downto 0)) = "01" then
      tx_rdy                 <= '1';
      tile_tx_f.data_valid <= status_reg(0);
    else
      tx_rdy                 <= '0';
      tile_tx_f.data_valid <= '0';
    end if;
  end process tx_stable;

  rx_stable : process (tile_rx_f.data_valid)
  begin  -- process rx_stable
--    if std_logic_vector(count(1 downto 0)) = "01" and tile_rx_f.data_valid = '1' then
    if tile_rx_f.data_valid = '1' then
      rx_rdy <= '1';
    else
      rx_rdy <= '0';
    end if;
  end process rx_stable;
  
end behav;
