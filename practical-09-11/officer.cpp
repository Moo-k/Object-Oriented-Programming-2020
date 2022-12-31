#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"
#include "officer.h"

officer::officer(){ // default constructor
    cerr << "constructed officer with no parameters" << endl; 
}
officer::officer(string inputName, int inputNRIC, string inputRank, int inputHeight){
    name = inputName;
    NRIC = inputNRIC;
    rank = inputRank;
    height = inputHeight;
    switch (rank.back()){
      case 'A':
        rankNumber = 10;
        pay = 5000;
        break;
      case 'J':
        rankNumber = 12;
        pay = 6700;
        break;
      case 'C':
        rankNumber = 13;
        pay = 8000;
        break;
      case 'L':
        rankNumber = 14;
        pay = 10000;
        break;
      case 'T':
        switch (rank.front()){
          case '2':
            rankNumber = 9;
            pay = 4800;
            break;
          case 'C':
            rankNumber = 11;
            pay = 6000;
            break;
          default:
            rankNumber = 0;
            break;
        }
      default:
        rankNumber = 0;
        pay = 0;
        break;
    }
}

//NRIC
void officer::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}
int officer::getNRIC(){
  return NRIC;
}

//NAME
void officer::setName(string inputName){
  name = inputName;
}
string officer::getName(){
  return name;
}

//RANK
void officer::setRank(string inputRank){
  rank = inputRank;
  switch (rank.back()){
      case 'A':
        rankNumber = 10;
        pay = 5000;
        break;
      case 'J':
        rankNumber = 12;
        pay = 6700;
        break;
      case 'C':
        rankNumber = 13;
        pay = 8000;
        break;
      case 'L':
        rankNumber = 14;
        pay = 10000;
        break;
      case 'T':
        switch (rank.front()){
          case '2':
            rankNumber = 9;
            pay = 4800;
            break;
          case 'C':
            rankNumber = 11;
            pay = 6000;
            break;
          default:
            rankNumber = 0;
            break;
        }
      default:
        rankNumber = 0;
        pay = 0;
        break;
    }
}
string officer::getRank(){
  return rank;
}
int officer::getRankNumber(){
  return rankNumber;
}

//PAY
void officer::setPay(int inputPay){
  pay = inputPay;
}
int officer::getPay(){
  return pay;
}

//HEIGHT
void officer::setHeight(int inputHeight){
  height = inputHeight;
}
int officer::getHeight(){
  return height;
}

//PRINT PARADE
void officer::printParade(){
  cout << " " << rank << " " << name.front() << " ";
}
//NAMETAG
string officer::generateNametag(){
  string output = " ";
  output.append(rank);
  output.append(" ");
  char firstInitial = name.front();
  output.append(&firstInitial);
  return output;
}

officer::~officer(){ //deconstructor
}
