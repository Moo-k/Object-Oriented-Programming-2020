#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Animal.h"
#include "Hunter.h"

Hunter::Hunter(string aSpecies){
	species = aSpecies;
	numberKills = 0;
}

void Hunter::record_kill(string kill){
	kills.push_back(kill);
	numberKills++;
}

int Hunter::numberOfKills(){
	return numberKills;
}

vector<string> Hunter::get_kills(){
	return kills;
}
