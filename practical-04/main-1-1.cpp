#include <iostream>
using namespace std;
#include <string>

extern void copy_2d_strings(string first[][2], string second[][2], int n);

int main(){
	string first[3][2] = {"hi","wr","ld"};
	string second[3][2];
	
	int n = 3;		
	
	copy_2d_strings(first,second,n);
	
	return 0;
}
