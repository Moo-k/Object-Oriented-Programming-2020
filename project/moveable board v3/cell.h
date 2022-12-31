#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

class cell{
public:
    cell();
    cell(char astate);
    char state; // W - wall, E - empty, S - skeleton, Z - zombie, C - coin
    void setstate(char state);
    char getstate();
    void printcell();
    ~cell();
};

#endif
