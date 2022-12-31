#include <iostream>
using namespace std;

extern int *readNumbers();
extern void printNumbers(int *numbers, int length);
extern bool equalsArray(int *numbers1, int* numbers2, int length);

int main(){
	int *numbers1 = readNumbers();
	int *numbers2 = readNumbers();
	
	if (equalsArray(numbers1,numbers2,5) == 1){
		cout << "The arrays are equal." << endl;
	}	else{
		cout << "The arrays are not equal." << endl;
	}
	
	return 0;
}
