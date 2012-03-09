#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
//#include <cstdio>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

enum port {North,East,South,West,Local,DC};

class STslot{
public:
	port ports[5];
	int x_direct;
	int y_direct;
	int x_src;
	int y_src;
	STslot(){
		for(int i = 0; i < 5; i++){
			ports[i] = DC;
		}
		x_direct = 0;
		y_direct = 0;
		x_src = 0;
		y_src = 0;
	}

};

class STprint{
	ofstream niST;
	ofstream routerST;

	string bin(int val, int bits) {
		string s = "";
		for (int i = 0; i < bits; ++i) {
			s += (val & (1 << (bits - i - 1))) != 0 ? "1" : "0";
		}
		return s;
	}

public:

	STprint(){
		niST = ofstream("ni_ST.vhd");
		routerST = ofstream("router_ST.vhd");
	}

	void writeHeaderRouter(int countWidth){
		routerST << "-------------------------------------------------------------\n";
		routerST << "-- router_ST.vhd\n";
		routerST << "-- This is an auto generated file, do not edit by hand.\n";
		routerST << "-------------------------------------------------------------\n";
		routerST << "library ieee;\n";
		routerST << "use ieee.std_logic_1164.all;\n";
		routerST << "use ieee.numeric_std.all;\n\n";

		routerST << "use work.leros_types.all;\n";
		routerST << "use work.noc_types.all;\n\n";

		routerST << "entity router_ST is\n";
		routerST << "\tport (\n";
		routerST << "\t\tcount\t: in unsigned(" << countWidth-1 << " downto 0);\n";
		routerST << "\t\tsels\t: out select_signals\n";
		routerST << "\t\t);\n";

		routerST << "end router_ST;\n\n";
		routerST << "architecture data of router_ST is\n";
		routerST << "begin -- data\n\n";
		routerST << "process(count) begin\n\n";
		routerST << "\tcase count is\n\n";

	}

	void endArchRouter(){
		routerST << "\t\twhen others => sels <= (others => 0);\n\n";
		routerST << "\tend case;\n";
		routerST << "end process;\n\n";
		routerST << "end data;\n";
	}

	void writeSlotRouter(int slotNum, int countWidth, port* ports){
		routerST << "\t\twhen \"" << bin(slotNum,countWidth) << "\" =>\n";
		if(ports[0] == 5 || ports[0] == 0){
			routerST << "\t\t\tsels(0) <= " << 0 << ";\n";
		} else{
			routerST << "\t\t\tsels(0) <= " << ports[0]-1 << ";\n";
		}
		if(ports[1] == 5 || ports[1] == 1){
			routerST << "\t\t\tsels(1) <= " << 0 << ";\n";
		} else if(ports[1] == 0){
			routerST << "\t\t\tsels(1) <= " << 3 << ";\n";
		} else{
			routerST << "\t\t\tsels(1) <= " << ports[1]-2 << ";\n";
		}
		if(ports[2] == 5 || ports[2] == 2){
			routerST << "\t\t\tsels(2) <= " << 0 << ";\n";
		} else if(ports[2] == 0 || ports[2] == 1){
			routerST << "\t\t\tsels(2) <= " << ports[2]+2 << ";\n";
		} else{
			routerST << "\t\t\tsels(2) <= " << ports[2]-3 << ";\n";
		}
		if(ports[3] == 5 || ports[3] == 3){
			routerST << "\t\t\tsels(3) <= " << 0 << ";\n";
		} else if(ports[3] == 4){
			routerST << "\t\t\tsels(3) <= " << 0 << ";\n";
		} else{
			routerST << "\t\t\tsels(3) <= " << ports[3]+1 << ";\n";
		}
		if(ports[4] == 5 || ports[4] == 4){
			routerST << "\t\t\tsels(4) <= " << 0 << ";\n";
		} else{
			routerST << "\t\t\tsels(4) <= " << ports[4] << ";\n";
		}
	}

	void writeHeaderNI(int countWidth, int numOfNodes){
		niST << "-------------------------------------------------------------\n";
		niST << "-- ni_ST.vhd\n";
		niST << "-- This is an auto generated file, do not edit by hand.\n";
		niST << "-------------------------------------------------------------\n";
		niST << "library ieee;\n";
		niST << "use ieee.std_logic_1164.all;\n";
		niST << "use ieee.numeric_std.all;\n\n";

		niST << "use work.leros_types.all;\n";
		niST << "use work.noc_types.all;\n\n";

		niST << "entity ni_ST is\n";
		niST << "\tgeneric (\n";
		niST << "\t\tNI_NUM\t: natural);\n";
		niST << "\tport (\n";
		niST << "\t\tcount\t: in unsigned(" << countWidth-1 << " downto 0);\n";
		niST << "\t\tdest\t: out integer range 0 to " << numOfNodes << ";\n";
		niST << "\t\tsrc\t: out integer range 0 to " << numOfNodes << "\n";
		niST << "\t\t);\n";

		niST << "end ni_ST;\n\n";
		niST << "architecture data of ni_ST is\n";
		niST << "begin -- data\n\n";

	}

	void startST(int num){
		niST << "\tNI_NUM" << num << " : if NI_NUM = " << num << " generate\n";
		niST << "\tprocess(count) begin\n\n";
		niST << "\t\tcase count is\n\n";
	}

	void writeSlotNIDest(int slotNum, int countWidth, int dest){
		niST << "\t\t\twhen \"" << bin(slotNum,countWidth) << "\" =>\n";
		niST << "\t\t\t\tdest <= " << dest << ";\n";
	}

	void writeSlotNISrc(int src){
		niST << "\t\t\t\tsrc <= " << src << ";\n";
	}

	void endST(int num){
		niST << "\t\t\twhen others =>\n";
		niST << "\t\t\t\tdest <= " << num << ";\n";
		niST << "\t\t\t\tsrc <= " << num << ";\n\n";
		niST << "\t\tend case;\n";
		niST << "\tend process;\n\n";
		niST << "\tend generate NI_NUM" << num << ";\n\n";
	}

	void endArchNI(){
		niST << "end data;\n";
	}
};

