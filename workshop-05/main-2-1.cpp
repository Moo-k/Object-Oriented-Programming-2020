#include <iostream>
using namespace std;

extern void hexDigits(int *numbers, int length);

int main(){

	int *numbers = NULL;
	int array[10] = {11,12,3,4,15,6,7,8,9,10};
	
	numbers = &array[0];
	
	hexDigits(numbers, 10);

	return 0;
}
