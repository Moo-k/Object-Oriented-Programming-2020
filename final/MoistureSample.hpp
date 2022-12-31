#ifndef MOISTURESAMPLE_H
#define MOISTURESAMPLE_H

class MoistureSample{
public:
	MoistureSample();
	MoistureSample(int inputsample_date, int inputeast_coordinate, int inputnorth_coordinate, int inputmoisture_content);
	void set_sample_date(string inputsample_date);
	void set_east_coordinate(int inputeast_coordinate);
	void set_north_coordinate(int inputnorth_coordinate);
	void set_moisture_content(int inputmoisture_content);
	int get_sample_date();
	int get_east_coordinate();
	int get_north_coordinate();
	int get_moisture_content();
private:
	int sample_date; // a value representing the date for a soil-moisture sample - decide on an appropriate type.
	int east_coordinate; // the offset measured in meters east from the south-west corner of the paddock in which the sample is taken. 
	int north_coordinate; // the offset measured in meters north from the south-west corner of the paddock in which the sample is taken.
	int moisture_content; // a value representing the the moisture content reading of the sample reading at the location and time. 
};

#endif
