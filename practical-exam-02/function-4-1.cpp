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

void displayArraySubsets(int *numbers,int length){
  for (int i = 0; i < length; i++){
    for (int j = i+1; j < length+1; j++){
      cout << "{";
      for (int k = i; k < j; k++){
        cout << *(numbers + k);
        if (k != j-1){
          cout << ",";
        }
      }
      cout << "}";
      if (j != length){
        cout << ",";
      }
    }
    cout << endl;
  }
}
