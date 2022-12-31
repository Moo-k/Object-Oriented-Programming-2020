#include <iostream>
using namespace std;

extern int *readNumbers();
extern int secondSmallestSum(int *numbers, int length);

int main(){
	const int length = 10;
	//int array[length] = {4,3,-4,-6,2,1};
	int *numbers = /*&array[0]*/readNumbers();
	
	cout << "The second smallest sum of any contiguous sub-array is " << secondSmallestSum(numbers,length) << "." << endl;
	
	return 0;
}
