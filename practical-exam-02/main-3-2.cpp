#include <iostream>
using namespace std;

extern int *createArray(int n);
extern void displayArray(int *numbers, int length);
extern bool equalsArray(int *A,int *B,int length);

int main(){
  const int n = 4;
  int *A = createArray(4);
  int *B = createArray(4);

  if (equalsArray(A,B,n) == true){
    cout << "true" << endl;
  } else{
    cout << "false" << endl;
  }

  return 0;
}
