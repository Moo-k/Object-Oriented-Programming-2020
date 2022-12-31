#include <iostream>
using namespace std;

extern int *readNumbers(/*int length*/);
extern bool equalsArray(int *numbers1, int *numbers2, int length);
extern int *reverseArray(int *numbers1, int length);

int main(){
	const int length = 10;
	cout << "Enter the elements of the array: " << endl;
	int *numbers1 = readNumbers(/*length*/);
	
	int *numbers2 = reverseArray(numbers1,length);
	
	if (equalsArray(numbers1,numbers2,length) == true){
		cout << "The array and its reverse are equal." << endl;
	}	else if (equalsArray(numbers1,numbers2,length) == false){
		cout << "The array and its reverse are not equal." << endl;
	}
	
	delete numbers1;
	delete numbers2;
	return 0;
}
