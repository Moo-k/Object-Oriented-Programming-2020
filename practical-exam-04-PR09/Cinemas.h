#ifndef CINEMAS_H
#define CINEMAS_H
#include <string>
#include "Cinema.h"
#include "EventCinemas.h"
using namespace std;

class Cinemas{
public:
    static void sort(EventCinemas **cinemas, int n);
};

#endif
