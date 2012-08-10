onerror {resume}
quietly WaveActivateNextPane {} 0

set SIDE_LENGTH 4
set NUM_NODES 16
set DUAL_CLK_NOC false

# Setting paths to all tile instances
for {set i 0} {$i<${SIDE_LENGTH}} {incr i} {
    for {set j 0} {$j<${SIDE_LENGTH}} {incr j} {
        if {$i == 0 && $j == 0} {
	   set "NODE_${j}_${i}" "/tb_noc/noc_test/tile_test/nodes_m(${j})/nodes_n(${i})/output_node/node"
	} else {
	  set "NODE_${j}_${i}" "/tb_noc/noc_test/tile_test/nodes_m(${j})/nodes_n(${i})/normal_node/node"
	}
    }
}

# Path to single clock Network Adapter
set NA "singleclkni/ni"
# Path to dual clock Network Adapter
#set NA "dualclkni/ni"

# Short form of add wave with the defined options
proc addwave {label path} {
     add wave -noupdate -radix hexadecimal -label $label $path
}


# Signals which only appear in the dual clock version
proc dualadd {first second} {
     global DUAL_CLK_NOC
     if {$DUAL_CLK_NOC} {addwave $first $second}
}

# Signals which only appear in the single clock version
proc singleadd {first second} {
     global DUAL_CLK_NOC
     if {!$DUAL_CLK_NOC} {addwave $first $second}
}

##############################################
## Adding the global signals
##############################################
add wave -noupdate /tb_noc/router_clk
add wave -noupdate /tb_noc/processor_clk
add wave -noupdate /tb_noc/reset

##############################################
## Leros_0_0
add wave -noupdate -divider -height 32 Leros_0_0
##############################################
addwave pc		$NODE_0_0/leros/fdout.pc
addwave accu		$NODE_0_0/leros/exout.accu
addwave processor_out 	$NODE_0_0/leros/ioout
addwave processor_out_mux $NODE_0_0/processor_out_mux
addwave processor_in 	$NODE_0_0/leros/ioin
addwave rd_data 	$NODE_0_0/$NA/rd_data
addwave tx_status_reg 	$NODE_0_0/$NA/tx_status_reg
addwave rx_status_reg 	$NODE_0_0/$NA/rx_status_reg
addwave south_in 	$NODE_0_0/south_in
addwave router/count 	$NODE_0_0/router_node/count
addwave local_out 	$NODE_0_0/router_node/local_out
addwave local_in 	$NODE_0_0/router_node/local_in
addwave out_rx_status 	$NODE_0_0/$NA/out_rx_status
addwave out_tx_status 	$NODE_0_0/$NA/out_tx_status
addwave tx_slot_dest 	$NODE_0_0/$NA/tx_slot_dest
addwave rx_slot_src 	$NODE_0_0/$NA/rx_slot_src

addwave router/count 	$NODE_0_0/router_node/count
addwave router/sels 	$NODE_0_0/router_node/sels
addwave na/count 	$NODE_0_0/$NA/count

singleadd TX_ram 	$NODE_0_0/$NA/TX_ram/ram
singleadd RX_ram 	$NODE_0_0/$NA/RX_ram/ram
dualadd ram 		$NODE_0_0/$NA/dp_ram/ram

##############################################
## Links
add wave -noupdate -divider -height 32 Links
##############################################


##############################################
## Leros_0_1
add wave -noupdate -divider -height 32 Leros_0_1
##############################################
addwave pc		$NODE_0_1/leros/fdout.pc
addwave accu 		$NODE_0_1/leros/exout.accu
addwave processor_out 	$NODE_0_1/leros/ioout
addwave processor_out_mux $NODE_0_1/processor_out_mux
addwave processor_in 	$NODE_0_1/leros/ioin
addwave tx_status_reg 	$NODE_0_1/$NA/tx_status_reg
addwave rx_status_reg 	$NODE_0_1/$NA/rx_status_reg

addwave north_out	$NODE_0_1/router_node/north_out
addwave east_out	$NODE_0_1/router_node/east_out
addwave south_out	$NODE_0_1/router_node/south_out
addwave west_out	$NODE_0_1/router_node/west_out
addwave local_out 	$NODE_0_1/router_node/local_out
addwave selsS           $NODE_0_1/router_node/sels
addwave north_in 	$NODE_0_1/router_node/north_in
addwave east_in 	$NODE_0_1/router_node/east_in
addwave south_in 	$NODE_0_1/router_node/south_in
addwave west_in 	$NODE_0_1/router_node/west_in
addwave local_in 	$NODE_0_1/router_node/local_in
addwave out_rx_status 	$NODE_0_1/$NA/out_rx_status
addwave out_tx_status 	$NODE_0_1/$NA/out_tx_status

addwave tx_slot_dest 	$NODE_0_1/$NA/tx_slot_dest
addwave tx_slot_status 	$NODE_0_1/$NA/tx_slot_status
addwave rx_slot_src 	$NODE_0_1/$NA/rx_slot_src
addwave rx_slot_status 	$NODE_0_1/$NA/rx_slot_status

singleadd TX_ram 	$NODE_0_1/$NA/TX_ram/ram
singleadd RX_ram 	$NODE_0_1/$NA/RX_ram/ram

##############################################
## Leros_1_0
add wave -noupdate -divider -height 32 Leros_1_0
##############################################
addwave pc		$NODE_1_0/leros/fdout.pc
addwave accu 		$NODE_1_0/leros/exout.accu
addwave processor_out 	$NODE_1_0/leros/ioout
addwave processor_in 	$NODE_1_0/leros/ioin
addwave tx_status_reg 	$NODE_1_0/$NA/tx_status_reg
addwave rx_status_reg 	$NODE_1_0/$NA/rx_status_reg

addwave local_out 	$NODE_1_0/router_node/local_out
addwave local_in 	$NODE_1_0/router_node/local_in
addwave out_rx_status 	$NODE_1_0/$NA/out_rx_status
addwave out_tx_status 	$NODE_1_0/$NA/out_tx_status

addwave tx_slot_dest 	$NODE_1_0/$NA/tx_slot_dest
addwave rx_slot_src 	$NODE_1_0/$NA/rx_slot_src
addwave router/count 	$NODE_1_0/router_node/count
addwave router/sels 	$NODE_1_0/router_node/sels

singleadd TX_ram 	$NODE_1_0/$NA/TX_ram/ram
singleadd RX_ram 	$NODE_1_0/$NA/RX_ram/ram


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
