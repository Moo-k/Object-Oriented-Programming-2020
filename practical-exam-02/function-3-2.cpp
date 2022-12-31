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

bool equalsArray(int *A,int *B,int length){
  for (int i = 0; i < length; i++){
    if (*(A+i)!=*(B+i)){
      return false;
    }
  }
  return true;
}
