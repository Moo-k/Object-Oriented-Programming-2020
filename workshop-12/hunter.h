#ifndef HUNTER_H
#define HUNTER_H
#include <string>
#include "animal.h"
using namespace std;


class hunter : public animal{
public:
    hunter(string n, int v);
    void set_kills(int k);
    int get_kills();
    string get_name();
private:
    int kills;
    static int nextID;
};

#endif
