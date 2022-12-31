#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "player.h"
#include "blackjack.h"

int main(void){
	player p1("Eugene",1000);
	blackjack b1;
	int yn;
	double winmult = 6;
	double bet = 0;
	
	while(b1.getgaming() == true){
		cout << "Enter bet amount: " << endl;
		cin >> bet;
		p1.player::credits -= bet;
    b1.resetgamestate();
		winmult = b1.round();
		cout << "win multiplier: " << winmult << endl;
		p1.player::credits += bet*winmult;
		cout << "Current credits: " << p1.getcredits() << endl;
		cout << "Keep Playing? (1 for Y; 2 for N)" << endl;
		cin >> yn;
		while (yn < 1 | yn > 2){
			cout << "Invalid input" << endl << "Keep Playing? (1 for Y; 2 for N)" << endl;
			cin >> yn;
		}
		b1.setgaming(yn);
	}
}
