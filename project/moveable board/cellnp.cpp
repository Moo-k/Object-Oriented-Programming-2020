#include <iostream>
using namespace std;
#include <string>
#include "cellnp.h"

//static int currplayerrowcoord = rows;
//static int currplayercolcoord = cols/2;

cell::cell(){
}

cell::cell(int arowcoord,int acolcoord, char astate){
	rowcoord = arowcoord;
	colcoord = acolcoord;
	state = astate;
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

void cell::setstate(char astate){
	state = astate;
}

char cell::getstate(){
	return state;
}

void cell::setprintout(char aprintout){
	printout = aprintout;
}

void cell::printcell(){
	cout << printout;
}

/*void cell::move(char direction){
  room[currplayerrowcoord][currplayercolcoord].setstate("Tile");
  room[currplayerrowcoord][currplayercolcoord].setprintout('.');
  switch(direction){
    case 'w':
      currplayerrowcoord--;
      break;
    case 'a':
      currplayercolcoord--;
      break;
    case 's':
      currplayerrowcoord++;
      break;
    case 'd':
      currplayercolcoord++;
      break;
  }
  room[currplayerrowcoord][currplayercolcoord].setstate("Player");
  room[currplayerrowcoord][currplayercolcoord].setprintout('O');
}*/

cell::~cell(){
}
