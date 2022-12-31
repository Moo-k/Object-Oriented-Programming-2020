#ifndef _ANIMAL_H
#define _ANIMAL_H
#include <iostream>
using namespace std;
#include <string>

class Animal{
public:
	Animal();
	Animal(string aspecies);
	static int currentID;
	string species;
	string name;
	int animalID;
	void set_name(string aname);
	string get_species();
	string get_name();
	int get_ID();
};

#endif
