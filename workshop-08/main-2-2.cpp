#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"
#include "Vegie.h"

int main(void){
	Animal a1("Elephant");
	Animal a2("Cheetah");
	
	a1.set_name("Ele");
	a2.set_name("Che");
	
	cout << "Species: " << a1.get_species() << ", Name: " << a1.get_name() << ", ID: " << a1.get_ID() << endl;
	cout << "Species: " << a2.get_species() << ", Name: " << a2.get_name() << ", ID: " << a2.get_ID() << endl;
	
	Vegie v1("Goat");
	cout << v1.species << "'s current favourite food: " << v1.getFavouriteFood() << endl;
	v1.set_favourite_food("Hats");
	cout << v1.species << "'s current favourite food: " << v1.getFavouriteFood() << endl;
}
