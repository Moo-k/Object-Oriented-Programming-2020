#include <iostream>
#include <stdlib.h>

extern int count_even(int number);

int main(){
  int number;
  std::cout << "Enter number: " << std::endl;
  std::cin >> number;

  std::cout << "There are " << count_even(number) << " even numbers from 1 to " << number << "." << std::endl;
  return 0;
}
