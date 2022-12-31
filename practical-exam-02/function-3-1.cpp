#include <iostream>
using namespace std;

int *createArray(int n){
  int *array = new int[n];
  for (int i = 0; i < n; i++){
    cin >> *(array + i);
  }
  return array;
}

void displayArray(int *numbers, int length){
  for (int i = 0; i < length; i++){
    cout << i << " " << *(numbers + i) << endl;
  }
}

int winningPowerBall(int *nums,int length){
  int winner = 0;
  for (int i = 0; i < length; i++){
    if (i % 2 == 0){
      winner += *(nums + i) * 2;
    } else {
      winner += *(nums + i);
    }
  }
  return winner;
}
