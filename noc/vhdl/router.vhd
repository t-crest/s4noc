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
  signal north_in_reg, north_in_buf : network_link_forward;
  signal south_in_reg, south_in_buf : network_link_forward;
  signal east_in_reg, east_in_buf   : network_link_forward;
  signal west_in_reg, west_in_buf   : network_link_forward;
  signal local_in_reg, local_in_buf : network_link_forward;

  component outnode
    port (
      clk   : in std_logic;
      reset : in std_logic;
      in0   : in network_link_forward;
      in1   : in network_link_forward;
      in2   : in network_link_forward;
      in3   : in network_link_forward;

      reg_out : out network_link_forward
      );
  end component;
  signal sel : std_logic_vector(1 downto 0);

begin

  north_output : outnode
    port map (in0     => local_in_reg, in1 => south_in_reg,
              in2     => east_in_reg, in3 => west_in_reg,
              clk     => clk, reset => reset,
              reg_out => north_out);

  south_output : outnode
    port map(in0     => north_in_reg, in1 => local_in_reg,
             in2     => east_in_reg, in3 => west_in_reg,
             clk     => clk, reset => reset,
             reg_out => south_out);


  east_output : outnode
    port map(in0     => north_in_reg, in1 => south_in_reg,
             in2     => local_in_reg, in3 => west_in_reg,
             clk     => clk, reset => reset,
             reg_out => east_out);


  west_output : outnode
    port map(in0     => north_in_reg, in1 => south_in_reg,
             in2     => east_in_reg, in3 => local_in_reg,
             clk     => clk, reset => reset,
             reg_out => west_out);


  local_output : outnode
    port map(in0     => north_in_reg, in1 => south_in_reg,
             in2     => east_in_reg, in3 => west_in_reg,
             clk     => clk, reset => reset,
             reg_out => local_out);



  north_in_buf.data       <= not (not north_in.data);
  north_in_buf.data_valid <= not (not north_in.data_valid);
  south_in_buf.data       <= not (not south_in.data);
  south_in_buf.data_valid <= not (not south_in.data_valid);
  east_in_buf.data        <= not (not east_in.data);
  east_in_buf.data_valid  <= not (not east_in.data_valid);
  west_in_buf.data        <= not (not west_in.data);
  west_in_buf.data_valid  <= not (not west_in.data_valid);
  local_in_buf.data       <= not (not local_in.data);
  local_in_buf.data_valid <= not (not local_in.data_valid);

  input_reg : process (clk, reset)
  begin  -- process input_reg
    if reset = '1' then                 -- asynchronous reset (active high)
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
    elsif rising_edge(clk) then         -- rising clock edge
      north_in_reg <= north_in_buf;
      south_in_reg <= south_in_buf;
      east_in_reg  <= east_in_buf;
      west_in_reg  <= west_in_buf;
      local_in_reg <= local_in_buf;
    end if;
  end process input_reg;

end architecture struct;

