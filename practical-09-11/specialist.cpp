#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"
#include "specialist.h"

specialist::specialist(){ // default constructor
    cerr << "constructed specialist with no parameters" << endl; 
}
specialist::specialist(string inputName, int inputNRIC, string inputRank, int inputHeight){
    name = inputName;
    NRIC = inputNRIC;
    rank = inputRank;
    height = inputHeight;
    switch (rank.front()){
      case '3':
        rankNumber = 4;
        pay = 2000;
        break;
      case '2':
        rankNumber = 5;
        pay = 2300;
        break;
      case '1':
        rankNumber = 6;
        pay = 3000;
        break;
      case 'S':
        rankNumber = 7;
        pay = 3600;
        break;
      case 'M':
        rankNumber = 8;
        pay = 4200;
        break;
      default:
        pay = 0;
        rankNumber = 0;
        break;
    }
}

//NRIC
void specialist::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}
int specialist::getNRIC(){
  return NRIC;
}

//NAME
void specialist::setName(string inputName){
  name = inputName;
}
string specialist::getName(){
  return name;
}

//RANK
void specialist::setRank(string inputRank){
  rank = inputRank;
  switch (rank.front()){
      case '3':
        rankNumber = 4;
        pay = 2000;
        break;
      case '2':
        rankNumber = 5;
        pay = 2300;
        break;
      case '1':
        rankNumber = 6;
        pay = 3000;
        break;
      case 'S':
        rankNumber = 7;
        pay = 3600;
        break;
      case 'M':
        rankNumber = 8;
        pay = 4200;
        break;
      default:
        pay = 0;
        rankNumber = 0;
        break;
    }
}
string specialist::getRank(){
  return rank;
}
int specialist::getRankNumber(){
  return rankNumber;
}

//PAY
void specialist::setPay(int inputPay){
  pay = inputPay;
}
int specialist::getPay(){
  return pay;
}

//HEIGHT
void specialist::setHeight(int inputHeight){
  height = inputHeight;
}
int specialist::getHeight(){
  return height;
}

//PRINT PARADE
void specialist::printParade(){
  cout << " " << rank << " " << name.front() << " ";
}
//NAMETAG
string specialist::generateNametag(){
  string output = " ";
  output.append(rank);
  output.append(" ");
  char firstInitial = name.front();
  output.append(&firstInitial);
  return output;
}

specialist::~specialist(){ //deconstructor
}
