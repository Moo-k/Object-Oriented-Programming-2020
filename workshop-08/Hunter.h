#ifndef _HUNTER_H
#define _HUNTER_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Animal.h"

class Hunter : public Animal{
public:
	Hunter(string aSpecies);
	string species;
	int numberKills;
	vector<string> kills;
	void record_kill(string kill);
	int numberOfKills();
	vector<string> get_kills();
};

#endif
