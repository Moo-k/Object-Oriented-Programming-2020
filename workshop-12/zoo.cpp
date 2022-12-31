#include <string>
using namespace std;
#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include "zoo.h"

zoo::zoo(string n,int cows,int lions){
  name = n;
  number_of_animals = cows + lions;
  animals = new animal*[number_of_animals];
  for (int i = 0; i < cows; i++){
    animals[i] = new vegie("Daisy",100);
  }
  for (int j = cows; j < cows+lions; j++){
    animals[j] = new hunter("Clarence",50);
  }
}

string zoo::get_name(){
  return name;
}

int zoo::get_number_of_animals(){
  return number_of_animals;
}

animal **zoo::get_animals(){
  return animals;
}
