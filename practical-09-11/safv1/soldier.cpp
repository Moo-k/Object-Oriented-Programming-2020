#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"

soldier::soldier(){ // default constructor
}

void soldier::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}

int soldier::getNRIC(){
  return NRIC;
}

void soldier::setName(string inputName){
  name = inputName;
}

string soldier::getName(){
  return name;
}

void soldier::setRank(string inputRank){
  rank = inputRank;
}

string soldier::getRank(){
  return rank;
}

int soldier::getRankNumber(){
  return 0;
}

void soldier::setPay(int inputPay){
  pay = inputPay;
}

int soldier::getPay(){
  return pay;
}

void soldier::setHeight(int inputHeight){
  height = inputHeight;
}

int soldier::getHeight(){
  return height;
}

void soldier::printParade(){
  cout << "       ";
}

soldier::~soldier(){ // destructor
}
