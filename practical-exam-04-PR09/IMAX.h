#ifndef IMAX_H
#define IMAX_H
#include <string>
#include "Cinema.h"
#include "EventCinemas.h"
using namespace std;

class IMAX : public EventCinemas{
public:
    IMAX();
    IMAX(float d);
    float discount;
    bool hasGroupRebate(int groupSize);
    float applyGroupRebate(int groupSize);
};

#endif
