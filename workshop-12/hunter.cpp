#include <string>
using namespace std;
#include "animal.h"
#include "hunter.h"

//static int 
int hunter::nextID = 1000;

hunter::hunter(string n, int v) : animal(n,v){
  animalID = nextID;
  nextID++;
  kills = 0;
}

void hunter::set_kills(int k){
  kills = k;
}

int hunter::get_kills(){
  return kills;
}

string hunter::get_name(){
  return "Hunter: " + name;
}
