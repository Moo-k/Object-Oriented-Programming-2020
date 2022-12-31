#include <math.h>

int binary_to_number(int binary_digits[], int number_of_digits){
    int dec = 0;

    for (int i = 0; i < number_of_digits; i++){
        if (binary_digits[i] == 1){
            dec += pow(2,(number_of_digits-i-1));
        }
    }

    return dec;
}