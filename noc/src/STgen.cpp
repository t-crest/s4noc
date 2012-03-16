#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
//#include <cstdio>
#include <algorithm>
#include <cctype>
#include <functional>
#include "STprint.cpp";

using namespace std;

int main(int argc,char *argv[]){
	if(argc < 3){
		cout << "Program need 2 arguments.\n\t1. Number of nodes\n\t2. Path for .shd file\n";
		return EXIT_SUCCESS;
	}
	int numOfNodes = atoi(argv[1]);
	string inputPath = argv[2];
	ifstream infile(inputPath, ifstream::in);
	vector<STslot> ST;
	STslot* slot = new STslot();
	string token;
	port inputPort = Local;
	int startTime = 0;
	STprint* printer = new STprint();

	while(infile.good()){
		getline(infile,token);
		std::string::size_type find = token.find_first_not_of(" ");
		startTime = (int)find;
		token.replace(0,startTime,"");
		cout << token << endl;

		if(startTime < 0){
			break; // The find_first_not_of() faild, we are done reading in routes.
		}

		for(unsigned i = 0; i < token.length(); i++){
			try{
				ST.at(startTime + i);
			} catch (out_of_range& oor){
				ST.push_back(*slot);
			}
			switch(token[i]){
			case 'n':
				if(ST.at(startTime + i).ports[North] == DC){
					ST.at(startTime + i).ports[North] = inputPort;
					inputPort = South;
					ST.at(startTime).y_dest++;
				} else {
					cout << "Epic faliure! North\n";
					return EXIT_FAILURE;
				}
				break;
			case 's':
				if(ST.at(startTime + i).ports[South] == DC){
					ST.at(startTime + i).ports[South] = inputPort;
					inputPort = North;
					ST.at(startTime).y_dest--;
				} else {
					cout << "Epic faliure! South\n";
					return EXIT_FAILURE;
				}
				break;
			case 'e':
				if(ST.at(startTime + i).ports[East] == DC){
					ST.at(startTime + i).ports[East] = inputPort;
					inputPort = West;
					ST.at(startTime).x_dest++;
				} else {
					cout << "Epic faliure! East\n";
					return EXIT_FAILURE;
				}
				break;
			case 'w':
				if(ST.at(startTime + i).ports[West] == DC){
					ST.at(startTime + i).ports[West] = inputPort;
					inputPort = East;
					ST.at(startTime).x_dest--;
				} else {
					cout << "Epic faliure! West\n";
					return EXIT_FAILURE;
				}
				break;
			}
		}
		try{
			ST.at(startTime + token.length());
		} catch (out_of_range& oor){
			ST.push_back(*slot);
		}
		if(ST.at(startTime + token.length()).ports[Local] == DC){
			ST.at(startTime + token.length()).ports[Local] = inputPort;
			ST.at(startTime + token.length()).x_src = -ST.at(startTime).x_dest;
			ST.at(startTime + token.length()).y_src = -ST.at(startTime).y_dest;
			inputPort = Local;
		} else {
			cout << "Epic faliure! Local\n";
			return EXIT_FAILURE;
		}

	}
	infile.close();
	int countWidth = (int)ceil(log((double)ST.size())/log(2.0));
	cout << countWidth << endl;
	printer->writeHeaderNI(countWidth,numOfNodes);
	printer->writeHeaderRouter(countWidth);

	for(unsigned i = 0; i < ST.size(); i++){
		printer->writeSlotRouter(i,countWidth,ST[i].ports);
	}

	printer->endArchRouter();

	int sideLength = (int)sqrt((double)numOfNodes);
	for (int nodeNum = 0; nodeNum < numOfNodes; nodeNum++){
		printer->startST(nodeNum);
		int xPos = nodeNum % sideLength;
		int yPos = (int)floor((double)nodeNum/sideLength);
		// TODO: The topology dependent generation of schedules should be given as a parameter
		// Generation of tables in mesh
		/*for(unsigned slotNum = 0; slotNum < ST.size(); slotNum++){
			int xDest = xPos + ST.at(slotNum).x_dest;
			int yDest = yPos + ST.at(slotNum).y_dest;
			int xSrc = xPos + ST.at(slotNum).x_src;
			int ySrc = yPos + ST.at(slotNum).y_src;
			if ((xDest < sideLength) && (xDest >= 0) && (yDest < sideLength) && (yDest >= 0)){
				int destNode = (yDest * sideLength) + xDest;
				printer->writeSlotNIDest(slotNum,countWidth,destNode);
			} else{
				printer->writeSlotNIDest(slotNum,countWidth,nodeNum);
			}
			if ((xSrc < sideLength) && (xSrc >= 0) && (ySrc < sideLength) && (ySrc >= 0)){
				int srcNode = (ySrc * sideLength) + xSrc;
				printer->writeSlotNISrc(srcNode);
			} else{
				printer->writeSlotNISrc(nodeNum);
			}
		}*/

		// Generation of tables in double torus
		for(unsigned slotNum = 0; slotNum < ST.size(); slotNum++){
			int xDest = xPos + ST.at(slotNum).x_dest;
			int yDest = yPos + ST.at(slotNum).y_dest;
			int xSrc = xPos + ST.at(slotNum).x_src;
			int ySrc = yPos + ST.at(slotNum).y_src;
			// Correction of destination and source address
			if (xDest < 0){xDest = xDest+sideLength;}
			else if(xDest >= sideLength){xDest = xDest-sideLength;}
			if (yDest < 0){yDest = yDest+sideLength;}
			else if(yDest >= sideLength){yDest = yDest-sideLength;}
			if (xSrc < 0){xSrc = xSrc+sideLength;}
			else if(xSrc >= sideLength){xSrc = xSrc-sideLength;}
			if (ySrc < 0){ySrc = ySrc+sideLength;}
			else if(ySrc >= sideLength){ySrc = ySrc-sideLength;}

			int destNode = (yDest * sideLength) + xDest;
			printer->writeSlotNIDest(slotNum,countWidth,destNode);
			int srcNode = (ySrc * sideLength) + xSrc;
			printer->writeSlotNISrc(srcNode);
		}
		printer->endST(nodeNum);
	}

	printer->endArchNI();

	return EXIT_SUCCESS;

}

