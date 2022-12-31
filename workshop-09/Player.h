#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player{
public:
	Player();
	char recentMove;
	int numMoves;
	virtual void move();
	virtual string getMoves();
	char getMove();
	bool win(Player* opponent);
	~Player();
};

#endif
