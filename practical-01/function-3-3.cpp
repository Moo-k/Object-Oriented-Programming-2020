#include <iostream>

double weightedaverage(int array[], int n){
  double sum = 0;
  double match = 0;
  double fraction = 0;
  if (n < 1){
    return 0;
  }

  for (int i = 0; i < n; i++){
    match = 0; // reset matches
    for (int j = 0; j < n; j++){ // find number of matches
      if (array[i] == array[j]){
        match++;
      }
    }
    fraction = match/n;
    sum += (array[i]*fraction); // int/int = int        int/double = double
    //std::cout << sum << std::endl;
  }
  return sum;
}
