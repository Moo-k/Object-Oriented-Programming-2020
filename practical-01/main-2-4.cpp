#include <iostream>

extern bool ascending(int[],int);

int main(){
  int n;
  std::cout << "Enter size of array: " << std::endl;
  std::cin >> n;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }

  std::cout << "Array is in ascending order: " << ascending(array,n) << std::endl;
  return 0;
}
