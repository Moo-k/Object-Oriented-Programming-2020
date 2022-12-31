#include <iostream>
using namespace std;

extern void cpyda(double *old_array, double *new_array, int length);

int main(){
	double old_array[10] = {0,1,2,3,4,5,6,7,8,9};
	double *new_array = new double[10];
	int length = 10;
	
	cpyda(old_array, new_array, length);
	return 0;
}
