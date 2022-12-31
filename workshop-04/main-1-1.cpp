#include <iostream>
using namespace std;

extern int size_of_variable_star_t();

int main(){

	cout << "The size of &t is " << size_of_variable_star_t() << endl;

	return 0;
	// 1-2: size of *t is the size of the value at the address t points to
	// 1-3: int *arr = new int[3] assigns pointer arr to array of 3 integers
}
