#include <iostream>
using namespace std;

int *readNumbers(){
	int *numbers = new int[10];
	
	for (int i = 0; i < 10; i++){
		//cout << "Enter number " << i+1 << ": ";
		cin >> *(numbers + i);
	}
	
	return numbers;
}

void printNumbers(int *numbers, int length){
	if (length > 0){
		for (int i = 0; i < length; i++){
			cout << i << " " << *(numbers + i) << endl;
		}
	}
}
