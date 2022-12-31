#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
using namespace std;
#include "Player.h"

class Computer : public Player{
public:
	Computer();
	Computer(string letter);
	void move();
	string getMoves();
	~Computer();
};

#endif
