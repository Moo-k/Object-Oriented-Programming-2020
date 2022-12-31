#include <iostream>
#include "KitchenAppliance.hpp"
using namespace std;

KitchenAppliance::KitchenAppliance(){
	isElectric = false;
}

KitchenAppliance::KitchenAppliance(bool inputisElectric){
	isElectric = inputisElectric;
}

bool KitchenAppliance::isElectrical(){
	cout << "IT’S FREE!" << endl;
	return isElectric;
}
