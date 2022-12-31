#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "aircraft.h"

int main(){
	person p1("Arvid",23000);
	person p2("Gary",21000);
	person p3("LarRy",30000);
	
	aircraft Fly("Fly",p1,p3);
	
	Fly.aircraft::printDetails();
	
	Fly.aircraft::setPilot(p3);
	Fly.aircraft::setCoPilot(p2);
	
	Fly.aircraft::printDetails();

	return 0;
}
