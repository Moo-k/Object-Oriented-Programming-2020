#include <iostream>
using namespace std;

extern int *readNumbers(/*int length*/);
extern bool equalsArray(int *numbers1, int *numbers2, int length);

int main(){
	const int length = 10;
	cout << "Enter the elements of array 1: " << endl;
	int *numbers1 = readNumbers(/*length*/);
	cout << "Enter the elements of array 2: " << endl;
	int *numbers2 = readNumbers(/*length*/);
	
	if (equalsArray(numbers1,numbers2,length) == true){
		cout << "The arrays are equal." << endl;
	}	else if (equalsArray(numbers1,numbers2,length) == false){
		cout << "The arrays are not equal." << endl;
	}
	
	delete numbers1;
	delete numbers2;
	return 0;
}
