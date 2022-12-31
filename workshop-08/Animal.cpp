#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"

int Animal::currentID = 0;

Animal::Animal(){
	species = "null";
	animalID = Animal::currentID;
	currentID++;
}

Animal::Animal(string aspecies){
	species = aspecies;
	animalID = Animal::currentID;
	currentID++;
}

void Animal::set_name(string aname){
	name = aname;
}

string Animal::get_species(){
	return species;
}

string Animal::get_name(){
	return name;
}

int Animal::get_ID(){
	return animalID;
}
