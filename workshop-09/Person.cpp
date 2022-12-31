#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Person.h"

Person::Person(){
}

void Person::move(){
	string a;
	char c;
	while (c != 'r' && c != 'R' && c != 'p' && c != 'P' && c != 's' && c != 'S'){
		cout << "Input move: " << endl;
		cin >> a;
		c = a[0];
	}
	recentMove = c;
	numMoves++;
}

string Person::getMoves(){
	string output;
	for (int i = 0; i < numMoves; i++){
		output.push_back(*(moves + i));
		output.push_back(' ');
	}
	return output;
}

Person::~Person(){
}
