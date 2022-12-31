#ifndef MONITORINGOFFICE_H
#define MONITORINGOFFICE_H

class MonitoringOffice{
public:
	MonitoringOffice();
	MonitoringOffice(string inputname);
	void set_name(string inputname);
	string get_name();
	FarmPaddock **get_farm_locations();
	void add_farm_paddock(FarmPaddock* new_farm_paddock);
private:
	FarmPaddock **farm_locations; // a vector of farm-paddocks monitored for soil moisture by this office.
	string department_name; // the name of the current government department responsible for monitoring soil moisture. 
};

#endif
