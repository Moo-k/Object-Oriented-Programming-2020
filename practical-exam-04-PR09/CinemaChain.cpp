#include <string>
#include "Cinema.h"
#include "EventCinemas.h"
#include "IMAX.h"
#include "CinemaChain.h"
using namespace std;

CinemaChain::CinemaChain(){
  cinemas = new Cinema*[5];
  cinemas[0] = new IMAX(0.5);
  cinemas[1] = new EventCinemas(5.0);
  cinemas[2] = new EventCinemas(7.0);
  cinemas[3] = new EventCinemas(3.0);
  cinemas[4] = new IMAX(2.0);
}

Cinema **CinemaChain::get_cinemas(){
  return cinemas;
}
