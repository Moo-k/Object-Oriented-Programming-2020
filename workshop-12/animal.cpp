#include <string>
using namespace std;
#include "animal.h"

//int animal::nextID = 0;

animal::animal(string n, int v){
  name = n;
  volume = v;
}

void animal::set_volume(int v){
  volume = v;
}

int animal::get_volume(){
  return volume;
}

void animal::set_name(string n){
  name = n;
}

string animal::get_name(){
  return name;
}

int animal::get_animalID(){
  return animalID;
}
