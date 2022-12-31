#include <iostream>

int median(int array[], int n){
  if (n < 1||n%2==0){
    return 0;
  }
  int median = 0;
  int temp = 0;
  int min = 0;

for (int k = 0; k < n; k++){
  for (int i = 0; i < n-1; i++){
    min = i;
    for (int j = i+1; j < n; j++){
      if (array[j] < array[min]){
        min = j;
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
      }
    }
  }
}

    median = array[(n-1)/2];

  return median;
}
