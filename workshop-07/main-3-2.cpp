#include <iostream>
using namespace std;

extern int *readNumbers();
extern void printNumbers(int *numbers, int length);
extern bool equalsArray(int *numbers1, int* numbers2, int length);
extern int *reverseArray(int *numbers1, int length);

int main(){
	int *numbers1 = readNumbers();
	int *numbers2 = reverseArray(numbers1, 10);
	
	if (equalsArray(numbers1,numbers2,10) == 1){
		cout << "The array and its reverse are equal." << endl;
	}	else{
		cout << "The array and its reverse are not equal." << endl;
	}
	
	return 0;
}
