#ifndef FARMPADDOCK_H
#define FARMPADDOCK_H

class FarmPaddock{
public:
	FarmPaddock();
	FarmPaddock(int inputid, int inputlongitude, int inputlatitude);
	void set_id(int inputid);
	void set_longitude(int inputlongitude);
	void set_latitude(int inputlatitude);
	int get_id();
	int get_longitude();
	int get_latitude();
	int get_current_time();
	void add_sample(MoistureSample* new_sample);
private:
	int id; // and identifier for this farm paddock location. 
	int longitude; // the longitude of the south west corner of the farm paddock. 
	int latitude; //the latitude of the south west corner of the farm paddock. 
	MoistureSample** samples:; // a vector containing all of the moisture-samples taken from this paddock.
};

#endif
