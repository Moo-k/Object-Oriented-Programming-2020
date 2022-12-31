#include <iostream>
using namespace std;

int main(void){
  int z = 1234;
  int a[2] = {51,56};
  int b = 765;
  int *ptr = &a[0];

  cout << *ptr << endl;
  cout << *(ptr + 1) << endl;
  cout << *(ptr + 2) << endl;
  cout << *(ptr - 1) << endl;
}
