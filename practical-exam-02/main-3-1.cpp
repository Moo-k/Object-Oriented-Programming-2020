#include <iostream>
using namespace std;

extern int *createArray(int n);
extern void displayArray(int *numbers, int length);
extern int winningPowerBall(int *nums,int length);

int main(){
  const int n = 4;
  int *numbers = createArray(4);

  cout << winningPowerBall(numbers, n) << endl;

  return 0;
}
