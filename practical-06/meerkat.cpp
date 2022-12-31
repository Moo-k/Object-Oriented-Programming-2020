#include <iostream>
using namespace std;
#include <string>
#include "meerkat.h"

meerkat::meerkat(){
}

void meerkat::setName(string meerName){
	name = meerName;
}

string meerkat::getName(){
	return name;
}

void meerkat::setAge(int meerAge){
	age = meerAge;
}

int meerkat::getAge(){
	return age;
}

meerkat::~meerkat(){
}
