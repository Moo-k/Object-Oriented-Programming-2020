#include <iostream>
using namespace std;

extern int *createArray(int n);
extern void displayArray(int *numbers, int length);

int main(){
  const int n = 4;
  int *numbers = createArray(4);

  displayArray(numbers,n);

  return 0;
}
