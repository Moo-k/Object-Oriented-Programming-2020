#include <iostream>
using namespace std;
#include "cell.h"

cell::cell(){
}

cell::cell(char astate){
  state = astate;
}

void cell::setstate(char astate){
  state = astate;
}

char cell::getstate(){
  return state;
}

void cell::printcell(){
  switch(state){
    case 'W':
      cout << "W ";
      break;
    case 'E':
      cout << ". ";
      break;
    case 'S':
      cout << "S ";
      break;
    case 'Z':
      cout << "Z ";
      break;
    case 'C':
      cout << "C ";
      break;
    case 'P':
      cout << "P ";
      break;
    default:
      cerr << "Error" << endl;
      break;
  }
}

cell::~cell(){
}
