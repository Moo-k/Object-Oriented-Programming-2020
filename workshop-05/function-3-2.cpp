#include <iostream>
using namespace std;

/*int *readNumbers(int length){
	const int len = length;
	int *numbers = new int[len];
	
	for (int i = 0; i < len; i++){
		//cout << "Enter number " << i+1 << ": ";
		cin >> *(numbers + i);
	}
	
	return numbers;
}*/

int *readNumbers(){
	int *numbers = new int[10];
	
	for (int i = 0; i < 10; i++){
		//cout << "Enter number " << i+1 << ": ";
		cin >> *(numbers + i);
	}
	
	return numbers;
}

bool equalsArray(int *numbers1, int *numbers2, int length){
	for (int i = 0; i < length; i++){
		if (*(numbers1 + i) != *(numbers2 + i)){
			return false;
		}
	}
	
	return true;
}

int *reverseArray(int *numbers1, int length){
	int *reversedArray = new int[length];
	
	for (int i = 0; i < length; i++){
		*(reversedArray + i) = *(numbers1 + length - 1 - i);
	}
	
	return reversedArray;
}
