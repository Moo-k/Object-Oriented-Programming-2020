#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Animal.h"
#include "Hunter.h"

int main(void){
	Animal a1("Elephant");
	Animal a2("Cheetah");
	
	a1.set_name("Ele");
	a2.set_name("Che");
	
	cout << "Species: " << a1.get_species() << ", Name: " << a1.get_name() << ", ID: " << a1.get_ID() << endl;
	cout << "Species: " << a2.get_species() << ", Name: " << a2.get_name() << ", ID: " << a2.get_ID() << endl;
	
	Hunter h1("Cheetah");
	h1.record_kill("Mouse");
	h1.record_kill("Gazelle");
	h1.record_kill("Gazelle");
	h1.record_kill("Hyena");
	h1.record_kill("Rabbit");
	h1.record_kill("Rabbit");
	
	vector<string> allKills = h1.get_kills();
	cout << "Hunter: " << h1.species << " has: " << h1.numberOfKills() << " kills." << endl;
	for (int i = 0; i < h1.numberOfKills(); i++){
		cout << allKills[i] << " ";
	}
	cout << endl;
}
