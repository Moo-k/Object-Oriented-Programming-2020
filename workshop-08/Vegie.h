#ifndef _VEGIE_H
#define _VEGIE_H
#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"

class Vegie : public Animal{
public:
	Vegie(string aSpecies);
	string species;
	string favFood;
	void set_favourite_food(string aVegie);
	string getFavouriteFood();
};

#endif
