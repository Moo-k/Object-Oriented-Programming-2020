#include <iostream>
using namespace std;

extern int diagonal(int[4][4]);

int main(){
    int array[4][4] = {
        {1,2,3,4},
        {2,3,4,5},
        {3,4,5,6},
        {4,5,6,7}
    };

    cout << "The sum of elements on the main diagonal is: " << diagonal(array) << endl;

    return 0;
}