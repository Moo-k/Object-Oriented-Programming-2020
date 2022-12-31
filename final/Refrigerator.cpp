#include <iostream>
#include "KitchenAppliance.hpp"
#include "Refrigerator.hpp"
using namespace std;

Refrigerator::Refrigerator(float inputcost) : KitchenAppliance(true){
	cost = inputcost;
}

void Refrigerator::isElectrical(){
	if (isElectric){
		cout << "$" << cost << "/month" << endl;
	}
}
