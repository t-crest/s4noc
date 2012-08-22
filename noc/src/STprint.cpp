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

enum port {N,E,S,W,L,D};
//         N E S W L D
//         0 1 2 3 4 5

class STslot{
public:
	port ports[5];
	int x_dest;
	int y_dest;
	int x_src;
	int y_src;
	STslot(){
		for(int i = 0; i < 5; i++){
			ports[i] = D;
		}
		x_dest = 0;
		y_dest = 0;
		x_src = 0;
		y_src = 0;
	}

};

class STprint{
	ofstream niST;
	ofstream routerST;

	char niST_name[20];
	char routerST_name[20];
	const int numOfNodes;

	string bin(int val, int bits) {
	int max = (int)pow(2.0,bits-1);
	string s = "";
	for(int i = 0; i < bits; i++){
		if(val/max >= 1){
			val -= max;
			s += "1";
		} else {
			s += "0";
		}
		max = max / 2;
	}
	return s;
}

public:

	STprint(int _numOfNodes): numOfNodes(_numOfNodes){
		sprintf(niST_name,"ni_ST_%i.vhd",numOfNodes);
		sprintf(routerST_name,"router_ST_%i.vhd",numOfNodes);
		niST.open(niST_name, ios::trunc);
		routerST.open(routerST_name, ios::trunc);
	}
	
	~STprint(){
		niST.close();
		routerST.close();
	}
	
	char p2c(port p){
		char c;
		if (p == N) c = 'N';
		if (p == E)	c = 'E';
		if (p == S)	c = 'S';
		if (p == W)	c = 'W';
		if (p == L)	c = 'L';
		if (p == D)	c = 'D';

		return c;
	}

	void writeHeaderRouter(int countWidth){
		routerST << "-------------------------------------------------------------\n";
		routerST << "-- " << routerST_name << "\n";
		routerST << "-- This is an auto generated file, do not edit by hand.\n";
		routerST << "-------------------------------------------------------------\n";
		routerST << "library ieee;\n";
		routerST << "use ieee.std_logic_1164.all;\n";
		routerST << "use ieee.numeric_std.all;\n\n";

		routerST << "use work.noc_types.all;\n\n";

		routerST << "entity router_ST_" << numOfNodes << " is\n";
		routerST << "\tgeneric (\n";
		routerST << "\t\tNI_NUM\t: natural\n";
		routerST << "\t\t);\n";
		routerST << "\tport (\n";
		routerST << "\t\tcount\t: in unsigned(" << countWidth-1 << " downto 0);\n";
		routerST << "\t\tsels\t: out select_signals\n";
		routerST << "\t\t);\n";

		routerST << "end router_ST_" << numOfNodes << ";\n\n";
		routerST << "architecture data of router_ST_" << numOfNodes << " is\n";
		routerST << "begin -- data\n\n";
		routerST << "process(count) begin\n\n";
		routerST << "\tsels(D) <= D;\n";
		routerST << "\tcase count is\n\n";

	}

	void endArchRouter(){
		routerST << "\t\twhen others => sels <= (others => D);\n\n";
		routerST << "\tend case;\n";
		routerST << "end process;\n\n";
		routerST << "end data;\n";
	}

	void writeSlotRouter(int slotNum, int countWidth, port* ports){
		routerST << "\t\twhen \"" << bin(slotNum,countWidth) << "\" =>\n";
		routerST << "\t\t\tsels(N) <= " << p2c(ports[N]) << ";\n";
		routerST << "\t\t\tsels(E) <= " << p2c(ports[E]) << ";\n";
		routerST << "\t\t\tsels(S) <= " << p2c(ports[S]) << ";\n";
		routerST << "\t\t\tsels(W) <= " << p2c(ports[W]) << ";\n";
		routerST << "\t\t\tsels(L) <= " << p2c(ports[L]) << ";\n";
	}

	void writeHeaderNI(int countWidth, int numOfNodes){
		niST << "-------------------------------------------------------------\n";
		niST << "-- " << niST_name << "\n";
		niST << "-- This is an auto generated file, do not edit by hand.\n";
		niST << "-------------------------------------------------------------\n";
		niST << "library ieee;\n";
		niST << "use ieee.std_logic_1164.all;\n";
		niST << "use ieee.numeric_std.all;\n\n";

		niST << "use work.noc_types.all;\n\n";

		niST << "entity ni_ST_" << numOfNodes << " is\n";
		niST << "\tgeneric (\n";
		niST << "\t\tNI_NUM\t: natural);\n";
		niST << "\tport (\n";
		niST << "\t\tcount\t: in unsigned(" << countWidth-1 << " downto 0);\n";
		niST << "\t\tdest\t: out integer range 0 to " << numOfNodes-1 << ";\n";
		niST << "\t\tsrc\t: out integer range 0 to " << numOfNodes-1 << "\n";
		niST << "\t\t);\n";

		niST << "end ni_ST_" << numOfNodes << ";\n\n";
		niST << "architecture data of ni_ST_" << numOfNodes << " is\n";
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

