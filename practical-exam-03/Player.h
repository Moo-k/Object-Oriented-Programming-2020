#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
using namespace std;
#include <string>

// player in a sport
class Player{
public:
    Player();
    int jerseyNumber;
    string playerName;
    Player(int jNumber, string pName);
    string get_name();
    int get_jersey_number();
    ~Player();
};

#endif
