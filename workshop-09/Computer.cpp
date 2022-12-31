#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Computer.h"

Computer::Computer(){
}

Computer::Computer(string letter){
	char mov = letter[0];
	if (mov == 'R' | mov == 'r' | mov == 'S' | mov == 's' | mov == 'P' | mov == 'p'){
		recentMove = mov;
	}	else{
		recentMove = 'r';
	}
}

void Computer::move(){
	numMoves++;
}

string Computer::getMoves(){
	string output;
	for (int i = 0; i < numMoves; i++){
		output.push_back(recentMove);
		output.push_back(' ');
	}
	return output;
}

Computer::~Computer(){
}
