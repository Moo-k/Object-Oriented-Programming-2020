#include <iostream>
using namespace std;
#include <string>
#include "person.h"

person::person(){
}

person::person(string aname, int height) : name(aname), height(height){
}

void person::setName(string aname){
	name = aname;
}

string person::getName(){
	return name;
}

void person::setHeight(int aheight){
	height = aheight;
}

int person::getHeight(){
	return height;
}
