#include <iostream>
using namespace std;

void cpyia(int old_array[], int new_array[], int length){
	//new_array = &old_array[0];
	
	for (int i = 0; i < length; i++){
		*(new_array + i) = *(old_array + i);
		//cout << new_array[i];
	}
	//cout << endl;
}
