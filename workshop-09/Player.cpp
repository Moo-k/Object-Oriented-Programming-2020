#include <iostream>
using namespace std;
#include "Player.h"

Player::Player(){
}

void Player::move(){ // allow child class to set recent move
	recentMove = 'r';
}

string Player::getMoves(){
	return "error";
}

char Player::getMove(){
	return 'e';
}

bool Player::win(Player* opponent){
	switch(recentMove){
		case 'r':
		case 'R':
			if (opponent->recentMove == 'P' | opponent->recentMove == 'p' | opponent->recentMove == 'r' | opponent->recentMove == 'R'){
				return false;
			}	else if (opponent->recentMove == 'S' | opponent->recentMove == 's'){
				return true;
			}
			break;
		case 'p':
		case 'P':
			if (opponent->recentMove == 'P' | opponent->recentMove == 'p' | opponent->recentMove == 's' | opponent->recentMove == 'S'){
				return false;
			}	else if (opponent->recentMove == 'R' | opponent->recentMove == 'r'){
				return true;
			}
			break;
		case 's':
		case 'S':
			if (opponent->recentMove == 'S' | opponent->recentMove == 's' | opponent->recentMove == 'r' | opponent->recentMove == 'R'){
				return false;
			}	else if (opponent->recentMove == 'P' | opponent->recentMove == 'p'){
				return true;
			}
			break;
	}
	return 0;
}

Player::~Player(){
}
