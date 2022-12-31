#include <iostream>
using namespace std;
#include <string>
#include "Player.h"

Player::Player(){
  playerName = "null";
  jerseyNumber = 0;
}

Player::Player(int jNumber, string pName){
  jerseyNumber = jNumber;
  playerName = pName;
}

string Player::get_name(){
  return playerName;
}

int Player::get_jersey_number(){
  return jerseyNumber;
}

Player::~Player(){}
