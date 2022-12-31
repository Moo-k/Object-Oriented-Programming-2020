#include <iostream>
using namespace std;

int main(void){

// global variables in the program
int list[5] = {1,2,3,4,5};
int *one=list;
int *two;

// pointer math
two=one;
two=two + 2;

// output from the pointers
std::cout << (two-one) << std::endl;
std::cout << ((char*)two-(char*)one) << std::endl;

}
