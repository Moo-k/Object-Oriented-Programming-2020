#include <iostream>
using namespace std;

int maximum_sum(int *nums, int length){
	int max = 0;
	int tempsum = 0;
	
	if (length == 1){
		max = *(nums);
	}
	
	for (int i = 0; i < length; i++){
		for (int j = i; j < length; j++){
			tempsum = 0;
			for (int k = i; k < j; k++){
				tempsum+=*(nums+k);
			}
			if (tempsum > max){
				max = tempsum;
			}
		}
	}
	
	return max;
}
