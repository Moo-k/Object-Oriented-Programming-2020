#include <iostream>
#include <stdlib.h>

extern double sumeven(double array[],int n);

int main(){
  int n;
  std::cout << "Enter array size: " << std::endl;
  std::cin >> n;

  double array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }

  std::cout << "The sum of values in even indexes is " << sumeven(array,n) << std::endl;
  return 0;
}
