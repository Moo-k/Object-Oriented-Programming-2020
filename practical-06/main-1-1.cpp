#include <iostream>
using namespace std;
#include <string>
#include "meerkat.h"

int main(){
	meerkat mk1;
	mk1.setName("Bob");
	mk1.setAge(42);
	
	cout << "Meerkat: " << mk1.getName() << " has age " << mk1.getAge() << endl;
	
	return 0;
}
