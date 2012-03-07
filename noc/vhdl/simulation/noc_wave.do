onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /tb_noc/router_clk
add wave -noupdate -radix hexadecimal /tb_noc/processor_clk
add wave -noupdate -radix hexadecimal /tb_noc/reset
add wave -noupdate -radix hexadecimal /tb_noc/ser_txd
add wave -noupdate -radix hexadecimal /tb_noc/ser_rxd


###############################
## Leros 1
add wave -noupdate -divider -height 32 Leros_1
###############################

add wave -noupdate -radix hexadecimal -label pc /tb_noc/tile_test/tile_1/leros/fd/pc
add wave -noupdate -radix hexadecimal -label accu /tb_noc/tile_test/tile_1/leros/ex/accu
add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/tile_test/tile_1/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_out /tb_noc/tile_test/tile_1/ni/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_in /tb_noc/tile_test/tile_1/ni/processor_in

add wave -noupdate -radix hexadecimal -label status_reg /tb_noc/tile_test/tile_1/ni/status_reg
add wave -noupdate -radix hexadecimal -label count /tb_noc/tile_test/tile_1/ni/count

add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/router_node/local_in
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/router_node/local_out


#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/tx_reg
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/tx_addr
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/tx_rdy

#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/rx_reg
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/rx_clr
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/rx_rdy

#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/tx_out
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/tile_tx_f.data
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/serdes/piso_phase


##############################
## Links
add wave -noupdate -divider -height 32 Links
##############################

add wave -noupdate -radix hexadecimal -label east_link /tb_noc/tile_test/east_link
add wave -noupdate -radix hexadecimal -label west_link /tb_noc/tile_test/west_link




##############################
## Leros 2
add wave -noupdate -divider -height 32 Leros_2
##############################

add wave -noupdate -radix hexadecimal -label pc /tb_noc/tile_test/tile_2/leros/fd/pc
add wave -noupdate -radix hexadecimal -label accu /tb_noc/tile_test/tile_2/leros/ex/accu
add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/tile_test/tile_2/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_out /tb_noc/tile_test/tile_2/ni/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_in /tb_noc/tile_test/tile_2/ni/processor_in

add wave -noupdate -radix hexadecimal -label status_reg /tb_noc/tile_test/tile_2/ni/status_reg
add wave -noupdate -radix hexadecimal -label count /tb_noc/tile_test/tile_2/ni/count



add wave -noupdate -radix hexadecimal -label rounter/west_out /tb_noc/tile_test/tile_2/router_node/west_out
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/router_node/local_in
add wave -noupdate -radix hexadecimal -label router/count /tb_noc/tile_test/tile_2/router_node/west_output/count



#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/tile_rx_f.data
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/rx_in


#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/tx_reg
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/tx_addr
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/tx_rdy

#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/rx_reg
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/rx_clr
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/rx_rdy


#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/serdes/piso_regs
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/serdes/next_piso_regs
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/serdes/piso_phase

#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/serdes/sipo_regs


TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {84126 ps} 0}
update
WaveRestoreZoom {0 ps} {210 ns}
