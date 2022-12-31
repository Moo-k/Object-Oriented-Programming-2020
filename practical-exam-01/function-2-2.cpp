#include <math.h>

int binary_to_number(int binary_digits[], int number_of_digits){
  int decimal = 0;

  for (int i = 0; i < number_of_digits; i++){
    if (binary_digits[i] == 1){
      decimal += pow(2,(number_of_digits-i-1)); // if 1, add 2^(what the space is worth)
    }
  }

  return decimal;
}
