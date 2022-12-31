#include <iostream>
using namespace std;
#include <string>
#include "person.h"

person::person(){
};

person::person(string myName,int Salary){
	name = myName;
	sal = Salary;
};

void person::setName(string myName){
	name = myName;
};

string person::getName(){
	return name;
};

void person::setSalary(int mySalary){
	sal = mySalary;
};

int person::getSalary(){
	return sal;
};
