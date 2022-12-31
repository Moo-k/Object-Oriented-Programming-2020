#include <iostream>
using namespace std;

extern bool is_a_palindrome(int integers[5],int length);
extern int sum_if_a_palindrome(int integers[5], int length);
extern int sum_elements(int integers[5], int length);

int main(){
    int integers[5] = {1,2,4,2,-17};
    int length = 5;

    if (is_a_palindrome(integers,length) == true){
        cout << "The sum of the palindrome array is " << sum_if_a_palindrome(integers,length) << endl;
    }   else{
        cout << "The sum of the palindrome array is " << sum_elements(integers,length) << endl;
    }

    return 0;
}