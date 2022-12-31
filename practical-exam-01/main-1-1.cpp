#include <iostream>
using namespace std;

extern void printer(int array[10][10]);

int main(void){
  int array[10][10];
  int pop = 1;

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){ // populate array so you dont have to type out 100 numbers
      array[i][j] = pop;
      pop++;
    }
  }

  printer(array);
}
