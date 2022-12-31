#ifndef _AIRCRAFT_H
#define _AIRCRAFT_H
#include <iostream>
using namespace std;
#include <string>
#include "person.h"

class aircraft{
public:
	person pilot;
	person coPilot;
	string callSign;
	aircraft(string callsign,person thePilot,person theCoPilot);
	void setPilot(person thePilot);      // change the pilot
	person getPilot();
	void setCoPilot(person theCoPilot);  // change the co-pilot
	person getCoPilot();
	void printDetails(); 
	~aircraft();
};

#endif
