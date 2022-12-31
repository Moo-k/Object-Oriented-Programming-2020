#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"
#include "general.h"

general::general(){ // default constructor
    cerr << "constructed general with no parameters" << endl; 
}

//constructor taking Name, NRIC, Rank and Height
general::general(string inputName, int inputNRIC, string inputRank, int inputHeight){
    name = inputName;
    NRIC = inputNRIC;
    rank = inputRank;
    height = inputHeight;
    switch (rank.front()){
      case 'B':
        rankNumber = 15;
        pay = 20000;
        break;
      case 'M':
        rankNumber = 16;
        pay = 40000;
        break;
      case 'L':
        rankNumber = 17;
        pay = 60000;
        break;
      default:
        rankNumber = 0;
        pay = 0;
        break;
    }
}

//implementation of setNRIC()
void general::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}

//implementation of getNRIC()
int general::getNRIC(){
  return NRIC;
}
//implementation of setName()
void general::setName(string inputName){
  name = inputName;
}
//implementation of getName()
string general::getName(){
  return name;
}
//implementation of setRank()
void general::setRank(string inputRank){
  rank = inputRank;
  switch (rank.front()){
      case 'B':
        rankNumber = 15;
        pay = 20000;
        break;
      case 'M':
        rankNumber = 16;
        pay = 40000;
        break;
      case 'L':
        rankNumber = 17;
        pay = 60000;
        break;
      default:
        rankNumber = 0;
        pay = 0;
        break;
    }
}

//implementation of getRank()
string general::getRank(){
  return rank;
}
//implementation of getRankNumber()
int general::getRankNumber(){
  return rankNumber;
}

//implementation of setPay()
void general::setPay(int inputPay){
  pay = inputPay;
}
//implementation of getPay()
int general::getPay(){
  return pay;
}

//implementation of setHeight()
void general::setHeight(int inputHeight){
  height = inputHeight;
}
//implementation of getHeight()
int general::getHeight(){
  return height;
}

//implementation of printParade()
void general::printParade(){
  cout << " " << rank << "  " << name.front() << " ";
}

//implementation of generateNametag()
string general::generateNametag(){
  string output = " ";
  output.append(rank);
  output.append("  ");
  char firstInitial = name.front();
  output.append(&firstInitial);
  return output;
}

//deconstructor
general::~general(){
}
