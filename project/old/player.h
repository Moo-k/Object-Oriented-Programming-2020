#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
using namespace std;
#include <string>

class player{
public:
	player();
	player(string aname,int acredits);
	string name;
	int credits;
	void setname(string aname);
	string getname();
	void setcredits(int acredits);
	int getcredits();
	~player();
};

#endif
