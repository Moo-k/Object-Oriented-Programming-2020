#include <iostream>
using namespace std;
int size_of_variable_star_arr(){
	int *arr = new int[3];
	//cout << *(arr) << endl;
	delete[] arr;
	//cout << *(arr) << endl;
	
	return sizeof(&arr);
}
