#include <iostream>
#include <stdlib.h>

extern int median(int array[], int n);

int main(){
  int n;
  std::cout << "Enter array size: " << std::endl;
  std::cin >> n;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }

  std::cout << "The median is " << median(array,n) << std::endl;
  return 0;
}
