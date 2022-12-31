#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int binAdd(int bin1, int bin2){
    int sum = 0;
    
    
    int temp = bin1;
    int base = 1;
    int last_digit = 0;
    
    while (temp > 0){
    last_digit = temp%10;
    temp /= 10;
    
    sum += base*last_digit;
    base *= 2;
    }
    
    temp = bin2;
    base = 1;
    while (temp > 0){
    last_digit = temp%10;
    temp /= 10;
    
    sum += base*last_digit;
    base *= 2;
    }    
    
    int binSum = 0;
    
    int dec = sum;
    int n = 0;

    while (dec > 1){
        dec /= 2;
        n++;
    }

    dec = sum;
    int r = 0;
    int bin[n];
    n = 0;

    while(dec > 0){
        r = dec%2;
        dec = dec/2;
        bin[n] = r;
        n++;
    }

    for (int j = n-1; j >= 0; j--){
    	if (bin[j] == 1){
    		binSum += pow(10,j);
    	}
    }

    return binSum;
}

/*int main(){
int bin1 = 0;
int bin2 = 0;

cout << "Enter first binary number: ";
cin >> bin1;

cout << "Enter second binary number: ";
cin >> bin2;

cout << "The sum is " << binAdd(bin1,bin2) << endl;

return 0;
}*/
