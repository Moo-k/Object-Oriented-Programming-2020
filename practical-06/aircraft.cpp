#include <iostream>
using namespace std;
#include <string>
#include "person.h"
#include "aircraft.h"

aircraft::aircraft(string callsign,person thePilot,person theCoPilot){
	callSign = callsign;
	pilot = thePilot;
	coPilot = theCoPilot;
}

void aircraft::setPilot(person thePilot){
	pilot = thePilot;	
}

person aircraft::getPilot(){
	return pilot;
}

void aircraft::setCoPilot(person theCoPilot){
	coPilot = theCoPilot;
}

person aircraft::getCoPilot(){
	return coPilot;
}

void aircraft::printDetails(){
	cout << callSign << endl << pilot.person::getName() << endl << coPilot.person::getName() << endl;
}

aircraft::~aircraft(){
	// cout << "deleted aircraft" << endl;
}
