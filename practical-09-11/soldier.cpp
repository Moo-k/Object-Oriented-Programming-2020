#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"

soldier::soldier(){ // default constructor
}

//NRIC
void soldier::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}
int soldier::getNRIC(){
  return NRIC;
}

//NAME
void soldier::setName(string inputName){
  name = inputName;
}
string soldier::getName(){
  return name;
}


//RANK
void soldier::setRank(string inputRank){
  rank = inputRank;
}
string soldier::getRank(){
  return rank;
}
int soldier::getRankNumber(){
  return 0;
}

//PAY
void soldier::setPay(int inputPay){
  pay = inputPay;
}
int soldier::getPay(){
  return pay;
}

//HEIGHT
void soldier::setHeight(int inputHeight){
  height = inputHeight;
}
int soldier::getHeight(){
  return height;
}

//PARADE
void soldier::printParade(){
  cout << "       ";
}

//NAMETAG
string soldier::generateNametag(){
  string output = "      ";
  return output;
}

soldier::~soldier(){ // destructor
}
