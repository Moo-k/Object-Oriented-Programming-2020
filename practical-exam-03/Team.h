#ifndef _TEAM_H
#define _TEAM_H
#include <iostream>
using namespace std;
#include <string>
#include "Player.h"

class Team{
public:
    Team();
    Team(int max_size, string name);
    string teamName;//////////
    int currentPlayers;///////  stuff in team
    int maxSize;//////////////
    Player *roster;///////////
    int get_current_number_of_players(); 
    string get_name();
    // returns the current roster as a pointer to players
    Player *get_roster();
    // adds player to team, returns false if unsuccessful
    bool add_player(Player new_player);
    ~Team();
};

#endif
