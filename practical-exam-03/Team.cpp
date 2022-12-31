#include <iostream>
using namespace std;
#include <string>
#include "Player.h"
#include "Team.h"

Team::Team(){
  int currentPlayers = 0;
};
  
Team::Team(int max_size, string name){
  maxSize = max_size;
  teamName = name;
  roster = new Player[maxSize];
}

int Team::get_current_number_of_players(){
  return currentPlayers;
}

string Team::get_name(){
  return teamName;
}

Player *Team::get_roster(){
  return roster;
}

bool Team::add_player(Player new_player){ // add new player to team, return false if unsuccessful
  if (currentPlayers == maxSize){
    return false;
  } else{
    roster[currentPlayers] = new_player;
    currentPlayers++;
    return true;
  }
}

Team::~Team(){}
