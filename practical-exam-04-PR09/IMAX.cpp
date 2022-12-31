#include <string>
#include "Cinema.h"
#include "EventCinemas.h"
#include "IMAX.h"
using namespace std;

IMAX::IMAX() : EventCinemas(){
}

IMAX::IMAX(float d){
  discount = d;
}

bool IMAX::hasGroupRebate(int groupSize){
  if (groupSize >= 5 && discount > 0){
    return true;
  } else{
    return false;
  }
}

float IMAX::applyGroupRebate(int groupSize){
  if (hasGroupRebate(groupSize)){
    return (discount * ticket * groupSize);
  } else{
    return (ticket * groupSize);
  }
}
