#include <iostream>
using namespace std;

extern int *createArray(int n);
extern void displayArray(int *numbers, int length);
extern void displayArraySubsets(int *numbers,int length);

int main(){
  const int n = 3;
  int *numbers = createArray(3);

  displayArraySubsets(numbers,n);

  return 0;
}
