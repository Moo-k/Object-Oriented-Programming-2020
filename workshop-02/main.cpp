#include <iostream>
using namespace std;
#include <string>
#include <math.h>

//extern int binAdd(int bin1, int bin2);
extern int print_as_binary(string decimal_number);

int main(){
    string decimal_number = "";
    int bin1 = 0;
    int bin2 = 0;
    
    cout << "Enter decimal number: ";
    cin >> decimal_number;

    cout << "Enter first binary number: ";
    cin >> bin1;

    cout << "Enter second binary number: ";
    cin >> bin2;
	
    cout << "The number in binary is " << print_as_binary(decimal_number) << endl;
    //cout << "The sum is " << binAdd(bin1,bin2) << endl;
return 0;
}
