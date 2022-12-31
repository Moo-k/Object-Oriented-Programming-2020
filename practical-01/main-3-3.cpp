#include <iostream>

extern double weightedaverage(int array[], int n);

int main(){
  int n;
  std::cout << "Enter array size: " << std::endl;
  std::cin >> n;

  int array[n];

  for (int i = 0; i < n; i++){
    std::cout << "Enter number: " << std::endl;
    std::cin >> array[i];
  }

  std::cout << "The weighted average is " << weightedaverage(array,n) << std::endl;
  return 0;
}
