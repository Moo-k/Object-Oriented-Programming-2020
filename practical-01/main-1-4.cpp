#include <iostream>
#include <stdlib.h>

extern int sumtwo(int array[], int secondarray[], int n);

int main(){
  int n;
  std::cout << "Enter size of array: " << std::endl;
  std::cin >> n;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number for first array: " << std::endl;
    std::cin >> array[i];
  }

  int secondarray[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number for second array: " << std::endl;
    std::cin >> secondarray[i];
  }

  std::cout << "The sum of elements in the array is: " << sumtwo(array,secondarray,n) << std::endl;
  return 0;
}
