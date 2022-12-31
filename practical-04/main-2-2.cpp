#include <iostream>
using namespace std;

extern int maximum_sum(int *nums, int length);

int main(){
	int array[10] = {31,-41,59,26,-53,58,97,-93,-23,84};
	int *nums = &array[0];
	int length = 10;
	
	
	cout << "The largest sum of a contiguous sub-array is " << maximum_sum(nums,length) << endl;
}
