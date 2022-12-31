#include <iostream>

int testFunction(int myArray[], int len) {
    return sizeof(myArray);
}

int main() {
    int array[] = {4, 7, 9};
    std::cout << "Size Array = " << sizeof(array);
    std::cout << "Inside Function = " <<   testFunction(array,sizeof(array)) << std::endl;
    return 0;
}
