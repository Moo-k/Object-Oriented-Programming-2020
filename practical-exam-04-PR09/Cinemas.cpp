#include "Cinema.h"
#include "EventCinemas.h"
#include "Cinemas.h"
using namespace std;

void Cinemas::sort(EventCinemas **cinemas, int n){
  int i = 0;
  while (i < n){
    if (i == 0){
      i++;
    } if (cinemas[i]->get_cinemaID() >= cinemas[i - 1]->get_cinemaID()){
      i++;
    } else{
      swap(cinemas[i], cinemas[i - 1]);
      i--;
    }
  }
}
