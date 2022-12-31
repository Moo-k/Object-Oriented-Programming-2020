#include <iostream>
using namespace std;

extern int identity(int array[10][10]);

int main(){
    int array[10][10] = {
        {1,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,1},
    };

    if (identity(array) == 1){
        cout << "The matrix is an identity matrix." << endl;
    }   else{
        cout << "The matrix is not an identity matrix." << endl;
    }

    return 0;
}