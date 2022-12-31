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

int secondSmallestSum(int *numbers, int length){
	int firstSmallestSum = *(numbers);
	int secondSmallestSum = *(numbers) + *(numbers+1);
	int tempSum = 0;
	
	for (int i = 0; i < length; i++){
		for (int j = i; j < length; j++){
			tempSum = 0;
			for (int k = i; k < j+1; k++){
				tempSum += *(numbers + k);
			}
			//cout << tempSum << endl;
			if (tempSum < firstSmallestSum){
				secondSmallestSum = firstSmallestSum;
				firstSmallestSum = tempSum;
			}	else if (tempSum > firstSmallestSum && tempSum < secondSmallestSum){
				secondSmallestSum = tempSum;
			}
		}
	}
	return secondSmallestSum;
}
