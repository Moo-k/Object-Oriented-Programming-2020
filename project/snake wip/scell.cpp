#include <iostream>
using namespace std;
#include "scell.h"

scell::scell(){
}

scell::scell(int axcoord, int aycoord, char astate, char adirection){
  xcoord = axcoord;
  ycoord = aycoord;
  state = astate;
  direction = adirection;
}

void scell::setdirection(char adirection){
  direction = adirection;
}

char scell::getdirection(){
  return direction;
}

void scell::setstate(char astate){
  state = astate;
}

char scell::getstate(){
  return state;
}

void scell::printcell(){
  switch(state){
    case 'H':
      switch(direction){
        case 'w':
          cout << "∧";
          break;
        case 'a':
          cout << "<";
          break;
        case 's':
          cout << "∨";
          break;
        case 'd':
          cout << ">";
          break;
        default:
          cerr << "Error" << endl;
          break;
      }
    case 'T':
      cout << "O";
      break;
    case 'E':
      cout << ".";
      break;
    case 'F':
      cout << "x";
      break;
    case 'W':
      cout << "#";
      break;
    case 'B':
      cout << "O";
      break;
    default:
      cerr << "Error" << endl;
      break;
  }
}

scell::~scell(){
}
