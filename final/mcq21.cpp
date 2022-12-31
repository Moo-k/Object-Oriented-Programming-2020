#include <iostream>
using namespace std;

class X {
    public:
        int x;
        X() { 
           x = 20; 
        }
};

class Y:public X {
    public:
        int y;
        Y() { 
           y = x + 1; 
        }
};

int main() {
    Y myY;
    X myX;
    
    
    cout << myX.x << endl;
    cout << myY.x << endl;
    cout << myY.y << endl;

}
