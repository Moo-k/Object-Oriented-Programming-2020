#include <string>
#include "Cinema.h"
#include "EventCinemas.h"
using namespace std;

int EventCinemas::filmID = 0;

EventCinemas::EventCinemas(){
}

EventCinemas::EventCinemas(float f){
  cinemaID = filmID;
  filmID++;
  ticket = f;
}


int EventCinemas::get_filmID(){
  return filmID;
}

void EventCinemas::set_filmID(int fid){
  filmID = fid;
}

int EventCinemas::get_cinemaID(){
  return cinemaID;
}

void EventCinemas::set_cinemaID(int cid){
  cinemaID = cid;
}

int EventCinemas::get_ticket(){
  return ticket;
}

void EventCinemas::set_ticket(int t){
  ticket = t;
}

float EventCinemas::get_ticketCost(){
  if (ticket <= 5){
    return ticket;
  } else{
    return ticket + 0.52;
  }
}
