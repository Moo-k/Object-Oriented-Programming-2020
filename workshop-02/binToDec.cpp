#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int binary_to_decimal(int binary){
    int dec = 0;
    int temp = binary;
    
    int base = 1;
    while (temp > 0){
    int last_digit = temp%10;
    temp /= 10;
    
    dec += base*last_digit;
    base *= 2;
    }
    
    return dec;
}

int main(){
    int binary = 0;
    cout << "Enter binary number: ";
    cin >> binary;

    cout << "The number in decimal is: " << binary_to_decimal(binary) << endl;

    return 0;
}
