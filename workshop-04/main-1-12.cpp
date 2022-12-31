#include <iostream>
using namespace std;

extern int size_of_variable_star_arr();

int main(){

	cout << "The size of &arr after deletion is " << size_of_variable_star_arr() << endl;
	
	//cout << "trying to print" << *(arr) << endl;

	return 0;
}
