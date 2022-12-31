#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Team.h"

int main(void){
  Player p1; // create p1
  Player p2(42,"Bob"); // create p2

  cout << "Name: " << p1.get_name() << ", Jersey Number: " << p1.get_jersey_number() << endl; // print p1
  cout << "Name: " << p2.get_name() << ", Jersey Number: " << p2.get_jersey_number() << endl; // print p2

  // add players to team
  Team t1(3,"t1"); // create t1 with 3 players max. name t1
  if (t1.add_player(p1) == true){cout << "added p1" << endl;} else{cout << "failed to add p1" << endl;} // add p1
  if (t1.add_player(p2) == true){cout << "added p2" << endl;} else{cout << "failed to add p2" << endl;} // add p2

  // print team details
  cout << "Team: " << t1.get_name() << ", has " << t1.get_current_number_of_players() << " players currently on the team, they are: " << endl; // test thingy
  Player *currRoster = t1.get_roster(); // set roster to pointer
  for (int i = 0; i < t1.get_current_number_of_players(); i++){ // for loop for each current member
    cout << currRoster[i].get_name() << " "; // get name of ith player
  }
  cout << endl;
}
