#include <iostream>
using namespace std;
#include <string>
#include "cell.h"

cell::cell(){
}

cell::cell(int arowcoord,int acolcoord, string astate, char aprintout){
	rowcoord = arowcoord;
	colcoord = acolcoord;
	state = astate;
	printout = aprintout;
}

void cell::setrowcoord(int arowcoord){
	rowcoord = arowcoord;
}

int cell::getrowcoord(){
	return rowcoord;
}

void cell::setcolcoord(int acolcoord){
	colcoord = acolcoord;
}

int cell::getcolcoord(){
	return colcoord;
}

void cell::setstate(string astate){
	state = astate;
}

string cell::getstate(){
	return state;
}

void cell::setprintout(char aprintout){
	printout = aprintout;
}

void cell::printcell(){
	cout << printout;
}

cell::~cell()
