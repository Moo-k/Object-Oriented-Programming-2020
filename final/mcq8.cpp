#include <iostream>
using namespace std;

class A {
  public:
    int f1() { return 5; }
    virtual int f2() { return 6; }
};

class B : public A {
  public:
    int f1() { return 7; }
    virtual int f2() { return 8; }
};

int main(void){

A* a1 = new A;
B* b1 = new B;
A* c1 = b1;

int result = b1->f2() + c1->f2() + c1->f1();
cout << result << endl;
}
