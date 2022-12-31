#include <iostream>
using namespace std;
#include <string>
#include "Player.h"

int main(void){
  // create players
  Player p1; // create p1 (name null, jersey no. 0)
  Player p2(42,"Bob");

  // print player details
  cout << "Name: " << p1.get_name() << ", Jersey Number: " << p1.get_jersey_number() << endl; // print p1
  cout << "Name: " << p2.get_name() << ", Jersey Number: " << p2.get_jersey_number() << endl; // print p2
}
