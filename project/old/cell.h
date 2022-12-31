#ifndef _CELL_H
#define _CELL_H
#include <iostream>
using namespace std;
#include <string>

class cell{
public:
	cell();
	cell(int arowcoord,int acolcoord, string astate);
	int rowcoord;
	int colcoord;
	string state;
	char printout;
	void setrowcoord(int arowcoord);
	int getrowcoord();
	void setcolcoord(int acolcoord);
	int getcolcoord();
	void setstate(string astate);
	string getstate();
	void setprintout(char aprintout);
	void printcell();
	~cell();
};

#endif
