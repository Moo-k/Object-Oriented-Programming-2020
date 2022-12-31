#include <iostream>
using namespace std;

int main(void){

int x[10] = {1,2,3,4,5,6,7,8,9,10};
int *y=&x[5];

cout <<  &x[5] << endl;
cout <<  x[5] << endl;
cout <<  *y << endl;
cout <<  (y-1)[1] << endl;
cout <<  &(y-1)[1] << endl;
cout << x+5  << endl;
cout <<  x[4]+1 << endl;
cout << *(x+5)  << endl;


}
