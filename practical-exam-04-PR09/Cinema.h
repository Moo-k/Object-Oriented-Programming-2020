#ifndef CINEMA_H
#define CINEMA_H
#include <string>
using namespace std;

class Cinema{
public:
    Cinema();
    Cinema(string t, bool f, int n);   // creates a cinema of type y, serves food f, number of theatres n
    void set_filmType(string c); 
    string get_filmType();
    void set_servesFood(bool f);
    bool get_servesFood();
    void set_numTheatres(int n);
    int get_numTheatres();
    virtual float get_ticketCost() = 0;
private:
    string filmType;         // the type of films played at Cinema, such as IMAX
    bool servesFood;         // states whether the Cinema serves food. 
    int numTheatres;         // the number of theatres at the cinema; takes only non-negative valu
};

#endif
