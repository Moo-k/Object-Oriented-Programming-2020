#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int print_as_binary(string decimal_number){
    int dec = stoi(decimal_number);

    int n = 0;

    while (dec > 0){
        dec /= 2;
        n++;
    }

    dec = stoi(decimal_number);
    int r = 0;
    int bin[n];
    n = 0;

    while(dec > 0){
        r = dec%2;
        dec /= 2;
        bin[n] = r;
        n++;
    }
    
    int output = 0;
    int temp = 0;

    for (int j = n-1; j >= 0; j--){
    	if (bin[j] == 1){
    		output += pow(10,j);
    	}
    }

    return output;
}

int main(){
    string decimal_number = "";
    
    cout << "Enter decimal number: ";
    cin >> decimal_number;

    cout << "The number in binary is " << print_as_binary(decimal_number) << endl;

    return 0;
}
