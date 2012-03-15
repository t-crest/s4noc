onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /tb_noc/router_clk
add wave -noupdate -radix hexadecimal /tb_noc/processor_clk
add wave -noupdate -radix hexadecimal /tb_noc/reset
#add wave -noupdate -radix hexadecimal /tb_noc/ser_txd
#add wave -noupdate -radix hexadecimal /tb_noc/ser_rxd


###############################
## Leros 1
add wave -noupdate -divider -height 32 Leros_1
###############################

add wave -noupdate -radix hexadecimal -label pc /tb_noc/tile_test/tile_1/leros/fd/pc
add wave -noupdate -radix hexadecimal -label accu /tb_noc/tile_test/tile_1/leros/ex/accu
#add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/tile_test/tile_1/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_out /tb_noc/tile_test/tile_1/ni/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_in /tb_noc/tile_test/tile_1/ni/processor_in

add wave -noupdate -radix hexadecimal -label tx_status_reg /tb_noc/tile_test/tile_1/ni/tx_status_reg
add wave -noupdate -radix hexadecimal -label rx_status_reg /tb_noc/tile_test/tile_1/ni/rx_status_reg
add wave -noupdate -radix hexadecimal -label count /tb_noc/tile_test/tile_1/ni/count


add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/router_node/local_in
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/router_node/local_out


add wave -noupdate -label dest_addr /tb_noc/tile_test/tile_1/ni/dest_addr
add wave -noupdate -label rx_slot_src /tb_noc/tile_test/tile_1/ni/rx_slot_src
add wave -noupdate -radix hexadecimal -label out_rx_status /tb_noc/tile_test/tile_1/ni/out_rx_status
add wave -noupdate -radix hexadecimal -label in_rx_status /tb_noc/tile_test/tile_1/ni/in_rx_status
add wave -noupdate -radix hexadecimal -label out_wr /tb_noc/tile_test/tile_1/ni/out_wr
add wave -noupdate -radix hexadecimal -label out_addr /tb_noc/tile_test/tile_1/ni/out_addr

#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/reg_tx_data_valid
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/reg_next_tx_data_valid
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/next_tx_data_valid
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_1/ni/next_next_tx_data_valid




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

#add wave -noupdate -radix hexadecimal -label pc /tb_noc/tile_test/tile_2/leros/fd/pc
#add wave -noupdate -radix hexadecimal -label accu /tb_noc/tile_test/tile_2/leros/ex/accu
#add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/tile_test/tile_2/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_out /tb_noc/tile_test/tile_2/ni/processor_out
add wave -noupdate -radix hexadecimal -label ni/processor_in /tb_noc/tile_test/tile_2/ni/processor_in

add wave -noupdate -radix hexadecimal -label tx_status_reg /tb_noc/tile_test/tile_2/ni/tx_status_reg
add wave -noupdate -radix hexadecimal -label rx_status_reg /tb_noc/tile_test/tile_2/ni/rx_status_reg
add wave -noupdate -radix hexadecimal -label count /tb_noc/tile_test/tile_2/ni/count
add wave -noupdate -radix hexadecimal -label count /tb_noc/tile_test/tile_2/router_node/count


#add wave -noupdate -radix hexadecimal -label rounter/west_out /tb_noc/tile_test/tile_2/router_node/west_out
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/router_node/local_in
add wave -noupdate -radix hexadecimal -label router/count /tb_noc/tile_test/tile_2/router_node/count

#add wave -noupdate -radix hexadecimal -label count /tb_noc/tile_test/tile_2/ni/count

add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/router_node/local_in
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/router_node/local_out

add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/reg_tx_data_valid
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/reg_next_tx_data_valid
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/next_tx_data_valid
add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/next_next_tx_data_valid

add wave -noupdate -radix hexadecimal -label registers /tb_noc/tile_test/tile_2/ni/dp_ram/ram
add wave -noupdate -radix hexadecimal -label out_en /tb_noc/tile_test/tile_2/ni/out_en
add wave -noupdate -radix hexadecimal -label out_wr /tb_noc/tile_test/tile_2/ni/out_wr
add wave -noupdate -radix hexadecimal -label tx_out /tb_noc/tile_test/tile_2/ni/tx_out
add wave -noupdate -radix hexadecimal -label out_tx_status /tb_noc/tile_test/tile_2/ni/out_tx_status
add wave -noupdate -label dest_addr /tb_noc/tile_test/tile_2/ni/dest_addr
add wave -noupdate -label rx_slot_src /tb_noc/tile_test/tile_2/ni/rx_slot_src

#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/tile_rx_f.data
#add wave -noupdate -radix hexadecimal /tb_noc/tile_test/tile_2/ni/rx_in

TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {84126 ps} 0}
update
WaveRestoreZoom {0 ps} {210 ns}
