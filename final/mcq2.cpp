#include <iostream>

// inc 1 function
int inc1(int y){
    y=y+1;
    return y;
}

// inc2 function
void inc2(int x){
    x=x+1;
}



int main() {
    int x=3;
    int y=6;
    x=inc1(x);
    inc2(x);
    inc2(x);
    y=inc1(x);
    
    std::cout << " x: " << x << " y: " << y << std::endl;
    return 0;
}
