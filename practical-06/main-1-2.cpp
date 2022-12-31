#include <iostream>
using namespace std;
#include <string>
#include "person.h"

int main(){
	person man1("ee",12);
	man1.setName("Bob");
	man1.setSalary(42);
	
	cout << "Person: " << man1.getName() << " has salary " << man1.getSalary() << endl;
	
	return 0;
}
