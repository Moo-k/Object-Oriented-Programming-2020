#include <iostream>
using namespace std;
#include <string>

void print_as_binary(string decimal_number){
    int dec = stoi(decimal_number);

    int n = 0;

    while (dec > 1){
        dec /= 2;
        n++;
    }

    dec = stoi(decimal_number);
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
        cout << bin[j];
    }

    cout<<endl;
}