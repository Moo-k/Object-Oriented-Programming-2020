#include <iostream>
#include <stdlib.h>

extern int count(int array[], int n, int number);

int main(){
  int n;
  std::cout << "Enter size of array: " << std::endl;
  std::cin >> n;

  int number;
  std::cout << "Enter desired number: " << std::endl;
  std::cin >> number;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }

  std::cout << "There are " << count(array,n,number) << " elements in the array that match the number given." << std::endl;
  return 0;
}
