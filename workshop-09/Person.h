#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
#include "Player.h"

class Person : public Player{
public:
	Person();
	char *moves;
	void move();
	string getMoves();
	~Person();
};

#endif
