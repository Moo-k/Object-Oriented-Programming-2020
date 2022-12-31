#include <iostream>
using namespace std;

int main(void){

char array[5] = {'1', '2', 'a', 'b', 'z'};
char *x;

x = &array[1];
*(x+2) = *(x+1);

for (int i = 0; i < 5; i++){
cout << array[i];
}
}
