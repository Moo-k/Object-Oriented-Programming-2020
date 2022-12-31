#include <iostream>
#include <stdlib.h>

extern double average(int[], int);

int main(){
  int n;
  std::cout << "Enter size of array: " << std::endl;
  std::cin >> n;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }
  std::cout << "The average of elements in the array is: " << average(array,n) << std::endl;
  return 0;
}
