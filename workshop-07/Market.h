#ifndef _MARKET_H
#define _MARKET_H
#include <string>
using namespace std;

class Market{
public:
	Market();
	string name;
	int age;
	void setName(string marName);
	string getName();
	void setAge(int merAge);
	int getAge();
};

#endif
