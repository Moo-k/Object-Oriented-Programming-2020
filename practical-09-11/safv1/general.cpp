#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"
#include "general.h"

general::general(){ // default constructor
    cerr << "constructed general with no parameters" << endl; 
}

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

void general::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}

int general::getNRIC(){
  return NRIC;
}

void general::setName(string inputName){
  name = inputName;
}

string general::getName(){
  return name;
}

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

string general::getRank(){
  return rank;
}

int general::getRankNumber(){
  return rankNumber;
}

void general::setPay(int inputPay){
  pay = inputPay;
}

int general::getPay(){
  return pay;
}

void general::setHeight(int inputHeight){
  height = inputHeight;
}

int general::getHeight(){
  return height;
}

void general::printParade(){
  cout << " " << rank << "  " << name.front() << " ";
}

general::~general(){
}
