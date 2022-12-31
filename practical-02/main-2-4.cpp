#include <iostream>
using namespace std;

extern int sum_min_and_max(int integers[5], int length);
extern int max_integer(int integers[5], int length);
extern int min_integer(int integers[5], int length);

int main(){
    int integers[5] = {1,3,5,6,7};
    int length = 5;

    int min = min_integer(integers,length);
    int max = max_integer(integers,length);
    int sum = sum_min_and_max(integers,length);

    cout << "Min: " << min << ", Max: " << max << ", Sum: " << sum << endl;
}