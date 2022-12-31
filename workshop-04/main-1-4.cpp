#include <iostream>
using namespace std;

extern int size_of_variable_star_arr();

int main(){

	cout << "The size of &arr is " << size_of_variable_star_arr() << endl;

	return 0;
}
