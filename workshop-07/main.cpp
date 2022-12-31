#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "wizard.h"

int main(void){
	person Guy;
	Guy.person::setName("Bob");
	Guy.person::setHeight(178);
	
	cout << "Name: " << Guy.person::getName() << ", Height: " << Guy.person::getHeight() << endl;
	
	wizard wiz;
	wiz.setName("Rob");
	wiz.setHeight(179);
	wiz.setMana(2);
	wiz.setSpell("Zap!");
	
	cout << "Name: " << wiz.getName() << ", Height: " << wiz.getHeight() << ", Mana: " << wiz.getMana() << ", Spell: " << wiz.getSpell() << endl;
	
	while(wiz.castSpell() == 1){
		cout << "Spell Casted: " << wiz.getSpell() << ", Remaining Mana: " << wiz.getMana() << endl;
	}
	wiz.setMana(3);
	cout << "Set mana of " << wiz.getName() << " to 3." << endl;
	while(wiz.castSpell() == 1){
		cout << "Spell Casted: " << wiz.getSpell() << ", Remaining Mana: " << wiz.getMana() << endl;
	}
	
	wizard wiz2;
	wiz2.setName("Meg");
	wiz2.setHeight(130);
	wiz2.setMana(1);
	wiz2.setSpell("Explosion!");
	
	while(wiz2.castSpell() == 1){
		cout << "Spell Casted: " << wiz2.getSpell() << ", Remaining Mana: " << wiz2.getMana() << endl;
	}
}
