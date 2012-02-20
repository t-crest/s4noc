onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /tb_noc/router_clk
add wave -noupdate -radix hexadecimal /tb_noc/processor_clk
add wave -noupdate -radix hexadecimal /tb_noc/reset
add wave -noupdate -radix hexadecimal /tb_noc/ser_txd
add wave -noupdate -radix hexadecimal /tb_noc/ser_rxd

add wave -noupdate -radix hexadecimal /tb_noc/tile1/leros/fd/pc

add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/count

add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/tx_reg
add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/tx_addr
add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/tx_rdy

add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/rx_reg
add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/rx_clr
add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/rx_rdy

add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/status_reg

add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/tx_out
add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/tile_tx_f.data
add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/serdes/piso_phase

add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/tile_rx_f.data
add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/rx_in


add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/tx_reg
add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/tx_addr
add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/tx_rdy

add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/rx_reg
add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/rx_clr
add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/rx_rdy

add wave -noupdate -radix hexadecimal /tb_noc/tile2/ni/status_reg

#add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/serdes/piso_regs
#add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/serdes/next_piso_regs
#add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/serdes/piso_phase

#add wave -noupdate -radix hexadecimal /tb_noc/tile1/ni/serdes/sipo_regs


TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {84126 ps} 0}
update
WaveRestoreZoom {0 ps} {210 ns}
