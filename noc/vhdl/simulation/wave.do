onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /tb_NI/router_clk
add wave -noupdate -radix hexadecimal /tb_NI/tile_clk
add wave -noupdate -radix hexadecimal /tb_NI/reset
add wave -noupdate -radix hexadecimal /tb_NI/tile_out_1
add wave -noupdate -radix hexadecimal /tb_NI/tile_in_1
add wave -noupdate -radix hexadecimal /tb_NI/leros_1/fd/pc

add wave -noupdate -radix hexadecimal /tb_NI/ni_1/count

add wave -noupdate -radix hexadecimal /tb_NI/ni_1/tx_reg
add wave -noupdate -radix hexadecimal /tb_NI/ni_1/tx_addr
add wave -noupdate -radix hexadecimal /tb_NI/ni_1/tx_rdy

add wave -noupdate -radix hexadecimal /tb_NI/ni_1/rx_reg
add wave -noupdate -radix hexadecimal /tb_NI/ni_1/rx_clr
add wave -noupdate -radix hexadecimal /tb_NI/ni_1/rx_rdy

add wave -noupdate -radix hexadecimal /tb_NI/ni_1/status_reg

add wave -noupdate -radix hexadecimal /tb_NI/ni_1/tx_out
add wave -noupdate -radix hexadecimal /tb_NI/ni_1/router_tx_f.data
add wave -noupdate -radix hexadecimal /tb_NI/ni_1/serdes_1/piso_phase

add wave -noupdate -radix hexadecimal /tb_NI/ni_2/router_rx_f.data
add wave -noupdate -radix hexadecimal /tb_NI/ni_2/rx_in


add wave -noupdate -radix hexadecimal /tb_NI/ni_2/tx_reg
add wave -noupdate -radix hexadecimal /tb_NI/ni_2/tx_addr
add wave -noupdate -radix hexadecimal /tb_NI/ni_2/tx_rdy

add wave -noupdate -radix hexadecimal /tb_NI/ni_2/rx_reg
add wave -noupdate -radix hexadecimal /tb_NI/ni_2/rx_clr
add wave -noupdate -radix hexadecimal /tb_NI/ni_2/rx_rdy

add wave -noupdate -radix hexadecimal /tb_NI/ni_2/status_reg

#add wave -noupdate -radix hexadecimal /tb_NI/ni_1/serdes_1/piso_regs
#add wave -noupdate -radix hexadecimal /tb_NI/ni_1/serdes_1/next_piso_regs
#add wave -noupdate -radix hexadecimal /tb_NI/ni_1/serdes_1/piso_phase

#add wave -noupdate -radix hexadecimal /tb_NI/ni_1/serdes_1/sipo_regs


TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {84126 ps} 0}
update
WaveRestoreZoom {0 ps} {210 ns}
