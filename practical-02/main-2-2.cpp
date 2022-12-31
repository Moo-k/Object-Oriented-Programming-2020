#include <iostream>
using namespace std;
#include <string>

extern int binary_to_number(int binary_digits[], int number_of_digits);

int main(){
    int binary_digits[5] = {1,1,1,0,0};
    int number_of_digits = 5;

    cout << "The number in decimal is: " << binary_to_number(binary_digits,number_of_digits) << endl;

    return 0;
}