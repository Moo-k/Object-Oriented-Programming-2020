#include <iostream>
#include <string>
using namespace std;
#include "soldier.h"
#include "man.h"

man::man(){ // default constructor
    cerr << "constructed man with no parameters" << endl; 
}

man::man(string inputName, int inputNRIC, string inputRank, int inputHeight){
    name = inputName;
    NRIC = inputNRIC;
    rank = inputRank;
    height = inputHeight;
    switch (rank.front()){
      case 'P':
        rankNumber = 1;
        pay = 580;
        break;
      case 'L':
        rankNumber = 2;
        pay = 600;
        break;
      case 'C':
        rankNumber = 3;
        pay = 650;
        break;
      default:
        rankNumber = 0;
        pay = 0;
        break;
    }
}

//NRIC
void man::setNRIC(int inputNRIC){
  NRIC = inputNRIC;
}
int man::getNRIC(){
  return NRIC;
}

//NAME
void man::setName(string inputName){
  name = inputName;
}
string man::getName(){
  return name;
}

//RANK
void man::setRank(string inputRank){
  rank = inputRank;
  switch (rank.front()){
      case 'P':
        rankNumber = 1;
        pay = 580;
        break;
      case 'L':
        rankNumber = 2;
        pay = 600;
        break;
      case 'C':
        rankNumber = 3;
        pay = 650;
        break;
      default:
        rankNumber = 0;
        pay = 0;
        break;
    }
}
string man::getRank(){
  return rank;
}
int man::getRankNumber(){
  return rankNumber;
}

//PAY
void man::setPay(int inputPay){
  pay = inputPay;
}
int man::getPay(){
  return pay;
}

//HEIGHT
void man::setHeight(int inputHeight){
  height = inputHeight;
}
int man::getHeight(){
  return height;
}

//PARADE
void man::printParade(){
  cout << " " << rank << " " << name.front() << " ";
}
//NAMETAG
string man::generateNametag(){
  string output = " ";
  output.append(rank);
  output.append(" ");
  char firstInitial = name.front();
  output.append(&firstInitial);
  return output;
}

man::~man(){ //deconstructor
}
