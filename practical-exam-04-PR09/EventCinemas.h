#ifndef EVENT_CINEMA_H
#define EVENT_CINEMA_H
#include <string>
#include "Cinema.h"
using namespace std;

class EventCinemas : public Cinema{
public:
    EventCinemas();
    EventCinemas(float f);
    int get_filmID();
    void set_filmID(int fid);
    int get_cinemaID();
    void set_cinemaID(int cid);
    int get_ticket();
    void set_ticket(int t);
    float ticket;
    int cinemaID;
    float get_ticketCost();
private:
    static int filmID;
};

#endif
