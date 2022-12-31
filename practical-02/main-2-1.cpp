#include <iostream>
using namespace std;
#include <string>

extern void print_as_binary(string decimal_number);

int main(){
    string decimal_number = "135";

    print_as_binary(decimal_number);

    return 0;
}