#ifndef _PERSON_H
#define _PERSON_H
#include <iostream>
using namespace std;
#include <string>

class person{
public:
	person();
	string name;
	int sal;
	person(string myName,int Salary);
	void setName(string myName);
	string getName();
	void setSalary(int mySalary);
	int getSalary();
};

#endif
