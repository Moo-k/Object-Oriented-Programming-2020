#include <iostream>
using namespace std;

extern int binary_to_number(int binary_digits[], int number_of_digits);

int main(void){
  int binary_digits[10] = {1,0,1,1,1,0,1,1,0,0}; // binary digits here
  int number_of_digits = 10;

  cout << "The number in decimal is " << binary_to_number(binary_digits, number_of_digits) << "." << endl;
}
