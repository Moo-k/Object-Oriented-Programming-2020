#ifndef _WIZARD_H
#define _WIZARD_H
#include <iostream>
using namespace std;
#include <string>
#include "person.h"

class wizard : public person{
public:
	int mana;
	string spell;
	wizard();
	wizard(int amana, string aspell);
	bool castSpell();
	void setMana(int amana);
	int getMana();
	void setSpell(string aspell);
	string getSpell();
};

#endif
