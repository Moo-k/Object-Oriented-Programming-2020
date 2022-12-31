#ifndef SCELL_H
#define SCELL_H
#include <iostream>
using namespace std;

class scell{
public:
    scell();
    scell(int axcoord, int aycoord, char astate, char adirection);
    int xcoord;
    int ycoord;
    char state; // H - head, T - tail, B - body, E - empty, F - food, W - wall
    char direction; // w, a, s, d
    void setdirection(char adirection);
    char getdirection();
    void setstate(char state);
    char getstate();
    void printcell();
    ~scell();
};

#endif
