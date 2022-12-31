#include <iostream>
using namespace std;

extern int sum_if_a_palindrome(int integers[], int length);
extern bool is_a_palindrome(int integers[], int length);
extern int sum_elements(int integers[], int length);

int main(void){
  int integers[7] = {1,3,7,8,7,3,1};
  int length = 7;

  if (is_a_palindrome(integers,length) == 1){ // checks if palindrome
    cout << "The sum of the palindrome array is " << sum_if_a_palindrome(integers,length) << "." << endl; // sum if palindrome (fancy way)
  } else{
    cout << "The sum of the non-palindrome array is " << sum_elements(integers,length) << "." << endl; // sum if not palindrome (boring)
  }
}
