#include <iostream>
#include <stdlib.h>

extern int sum_array(int[], int);

int main(){
  int n;
  std::cout << "Enter size of array: " << std::endl;
  std::cin >> n;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }
  std::cout << "The sum of elements in the array is: " << sum_array(array,n) << std::endl;
  return 0;
}
