#include <iostream>
using namespace std;

extern void cpyia(int old_array[], int new_array[], int length);

int main(){
	int old_array[10] = {0,1,2,3,4,5,6,7,8,9};
	int new_array[10];
	int length = 10;
	
	cpyia(old_array, new_array, length);
	return 0;
}
