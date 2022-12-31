#include <string>
#include "Cinema.h"
using namespace std;

Cinema::Cinema(){
}

Cinema::Cinema(string t, bool f, int n){
  filmType = t;
  servesFood = f;
  numTheatres = n;
}

void Cinema::set_filmType(string c){
  filmType = c;
}

string Cinema::get_filmType(){
  return filmType;
}

void Cinema::set_servesFood(bool f){
  servesFood = f;
}

bool Cinema::get_servesFood(){
  return servesFood;
}

void Cinema::set_numTheatres(int n){
  numTheatres = n;
}

int Cinema::get_numTheatres(){
  return numTheatres;
}
