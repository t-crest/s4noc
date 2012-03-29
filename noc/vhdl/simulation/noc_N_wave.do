onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /tb_noc/router_clk
add wave -noupdate /tb_noc/processor_clk
add wave -noupdate /tb_noc/reset
##############################################
## Leros_0_0
add wave -noupdate -divider -height 32 Leros_0_0
##############################################

add wave -noupdate -radix hexadecimal -label pc /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/leros/fdout.pc
add wave -noupdate -radix hexadecimal -label accu /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/leros/exout.accu
add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/leros/ioout
add wave -noupdate -radix hexadecimal -label processor_in /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/leros/ioin
add wave -noupdate -radix hexadecimal -label tx_status_reg /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/ni/tx_status_reg
add wave -noupdate -radix hexadecimal -label rx_status_reg /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/ni/rx_status_reg
add wave -noupdate -radix hexadecimal -label south_in /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/south_in
add wave -noupdate -radix hexadecimal /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/router_node/count
add wave -noupdate -radix hexadecimal -label local_out /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/router_node/local_out

add wave -noupdate -radix hexadecimal -label router/count /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/router_node/count
add wave -noupdate -radix hexadecimal -label ni/count /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/ni/count
add wave -noupdate -radix hexadecimal -label out_phase /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/ni/out_phase
add wave -noupdate -radix hexadecimal -label ram /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(0)/output_node/node/ni/dp_ram/ram

##############################################
## Links
add wave -noupdate -divider -height 32 Links
##############################################


##############################################
## Leros_0_1
add wave -noupdate -divider -height 32 Leros_0_1
##############################################
add wave -noupdate -radix hexadecimal -label pc /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(1)/normal_node/node/leros/fdout.pc
add wave -noupdate -radix hexadecimal -label accu /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(1)/normal_node/node/leros/exout.accu
add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(1)/normal_node/node/leros/ioout
add wave -noupdate -radix hexadecimal -label processor_in /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(1)/normal_node/node/leros/ioin
add wave -noupdate -radix hexadecimal -label tx_status_reg /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(1)/normal_node/node/ni/tx_status_reg
add wave -noupdate -radix hexadecimal -label rx_status_reg /tb_noc/noc_test/tile_test/nodes_m(0)/nodes_n(1)/normal_node/node/ni/rx_status_reg

##############################################
## Leros_1_0
add wave -noupdate -divider -height 32 Leros_1_0
##############################################
add wave -noupdate -radix hexadecimal -label pc /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/leros/fdout.pc
add wave -noupdate -radix hexadecimal -label accu /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/leros/exout.accu
add wave -noupdate -radix hexadecimal -label processor_out /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/leros/ioout
add wave -noupdate -radix hexadecimal -label processor_in /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/leros/ioin
add wave -noupdate -radix hexadecimal -label tx_status_reg /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/ni/tx_status_reg
add wave -noupdate -radix hexadecimal -label rx_status_reg /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/ni/rx_status_reg

add wave -noupdate -radix hexadecimal -label north_out /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/north_out

add wave -noupdate -radix hexadecimal -label local_in /tb_noc/noc_test/tile_test/nodes_m(1)/nodes_n(0)/normal_node/node/router_node/local_in


TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {84 ns} 0}
configure wave -namecolwidth 148
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ns} {170 ns}
