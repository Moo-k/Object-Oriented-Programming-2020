#include <iostream>
using namespace std;
#include <string>
#include "Animal.h"

int main(void){
	Animal a1("Elephant");
	Animal a2("Cheetah");
	
	a1.set_name("Ele");
	a2.set_name("Che");
	
	cout << "Species: " << a1.get_species() << ", Name: " << a1.get_name() << ", ID: " << a1.get_ID() << endl;
	cout << "Species: " << a2.get_species() << ", Name: " << a2.get_name() << ", ID: " << a2.get_ID() << endl;
}
