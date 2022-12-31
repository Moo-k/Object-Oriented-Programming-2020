#ifndef VEGIE_H
#define VEGIE_H
#include <string>
using namespace std;
#include "animal.h"

class vegie : public animal{
public:
    vegie(string n, int v);
    void set_favourite_food(string f);
    string get_favourite_food();
    string get_name();
private:
    string favourite_food;
    static int nextID;
};

#endif
