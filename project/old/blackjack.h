#ifndef _BLACKJACK_H
#define _BLACKJACK_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <random>
#include "player.h"

class blackjack{
public:
	blackjack();
	bool gaming;
    static int array[2];
    static int *ace;
	vector<int*> deck;
	vector<int*> playerhand;
	vector<int*> dealerhand;
    vector<int> indexesdrawn;
	int* drawcard();
	int dealertotal;
	int playertotal;
	int maxunder21(vector<int*> hand);
	bool getgaming();
	void setgaming(int yn);
	void resetgamestate();
	double round();
	~blackjack();
};

#endif
