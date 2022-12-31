#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"
#include "Vegie.h"

Vegie::Vegie(string aSpecies){
	species = aSpecies;
	favFood = "Grass";
}

void Vegie::set_favourite_food(string aVegie){
	favFood = aVegie;
}

string Vegie::getFavouriteFood(){
	return favFood;
}
