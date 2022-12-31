#ifndef _MEERKAT_H
#define _MEERKAT_H
#include <iostream>
using namespace std;
#include <string>

class meerkat{
public:
	meerkat();
	string name;
	int age;
	void setName(string meerName);
	string getName();
	void setAge(int meerAge);
	int getAge();
	~meerkat();
};

#endif
