//player.cpp
#include "cell.h"
#include "entity.h"
#include "player.h"
#include <string>
#include <iostream>

using namespace std;

//implementing default arrow constructor
player::player():entity()
{
    health = 25;
    attack = 2;
    score = 1;
}

int player::getAttack()
{
    return attack;
}

int player::getHealth()
{
    return health;
}

void player::modifyAttack(int pattack){
    attack = pattack;
}

void player::modifyHealth(int phealth){
    health = phealth;
}

void player::modifyRowCoord(int prow){
    rowCoord = prow;
}

int player::getRowCoord(){
    return rowCoord;
}

void player::modifyColCoord(int pcol){
    colCoord = pcol;
}

int player::getColCoord(){
    return colCoord;
}

int player::getScore(){
    return score;
}

void player::modifyScore(int pscore){
    score = pscore;
}

//implementing player deconstructor
player::~player()
{
}
