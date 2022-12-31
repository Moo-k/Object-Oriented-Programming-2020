#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "wizard.h"

wizard::wizard(){
}

wizard::wizard(int amana, string aspell){
	mana = amana;
	spell = aspell;
}

bool wizard::castSpell(){
	if (mana == 0){
		return false;
	}	else{
		cout << spell << endl;
		mana -= 1;
		return true;
	}
}

void wizard::setMana(int amana){
	mana = amana;
}

int wizard::getMana(){
	return mana;
}

void wizard::setSpell(string aspell){
	spell = aspell;
}

string wizard::getSpell(){
	return spell;
}
