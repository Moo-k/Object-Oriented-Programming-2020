#include <iostream>
using namespace std;
#include <string>
#include "player.h"

player::player(){
	name = "NULL";
	credits = 0;
}

player::player(string aname,int acredits){
	name = aname;
	credits = acredits;
}

void player::setname(string aname){
	name = aname;
}

string player::getname(){
	return name;
}

void player::setcredits(int acredits){
	credits = acredits;
}

int player::getcredits(){
	return credits;
}

player::~player(){
}
