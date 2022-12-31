#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Person.h"
#include "Computer.h"

int main(void){
	Person p1;
	Computer c1 = Computer();
	Computer c2 = Computer("R");
	p1.move();
	
	if (p1.win(&c2) == true){
		cout << "You win!" << endl;
	}	else{
		cout << "You do not win!" << endl;
	}
}
