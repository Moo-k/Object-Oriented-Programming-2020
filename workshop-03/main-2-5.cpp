#include <iostream>
using namespace std;

int main(void){
  int array[5][5] = {{1,2,3,4,5},
                     {2,3,4,5,6},
                     {3,4,5,6,7},
                     {4,5,6,7,8},
                     {5,6,7,8,9}};
  int **dbl = new int*[5];

  for (int i = 0; i < 5; i++){
    *(dbl + i) = *(array + i);
  }

  for (int j = 0; j < 5; j++){
    for (int k = 0; k < 5; k++){
      cout << *(*(dbl+j)+k) << " ";
    }
    cout << endl;
  }

  cout << endl;

}

