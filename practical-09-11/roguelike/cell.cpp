#include <iostream>
using namespace std;
#include "cell.h"

cell::cell(){
}

cell::cell(char astate){
  state = astate;
}

void cell::setState(char astate){
  state = astate;
}

char cell::getState(){
  return state;
}

void cell::printCell(){
  switch(state){
    case 'W': //wall
      cout << "W ";
      break;
    case 'E': //empty
      cout << ". ";
      break;
    case 'S': //Skeleton
      cout << "S ";
      break;
    case 'Z': //Zombie
      cout << "Z ";
      break;
    case 'C': //Coins
      cout << "C ";
      break;
    case 'P': //player
      cout << "P ";
      break;
    case 'A': //apple
      cout << "A ";
      break;
    case 'K': //knife
      cout << "K ";
      break;
    case 'X': //Elixir
      cout << "X ";
      break;
    case '*': // Arrow
      cout << "* ";
      break;
    default:
      cerr << "Error" << endl;
      break;
  }
}

cell::~cell(){
}
