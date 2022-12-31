#ifndef _PERSON_H
#define _PERSON_H
#include <iostream>
using namespace std;
#include <string>

class person{
public:
	string name;
	int height;
	person();
	person(string aname, int height);
	void setName(string aname);
	string getName();
	void setHeight(int aheight);
	int getHeight();
};

#endif
