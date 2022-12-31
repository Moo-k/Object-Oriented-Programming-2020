//entity.cpp
#include <iostream>
#include <string>
#include "cell.h"
#include "entity.h"

using namespace std;

//item default constructor
entity::entity()
{
    health=0;
    attack=0;
}

//entity constructor taking ehealth and eattack as parameters
entity::entity(int erow, int ecol, int ehealth,int eattack)
{
    rowCoord = erow;
    colCoord = ecol;
    health = ehealth;
    attack = eattack;
}

void entity::modifyRowCoord(int erow){
    rowCoord = erow;
}

int entity::getRowCoord(){
    return rowCoord;
}

void entity::modifyColCoord(int ecol){
    colCoord = ecol;
}

int entity::getColCoord(){
    return colCoord;
}

//implementing set health function
void entity::modifyHealth(int ehealth)
{
    health = ehealth;
}
//get health function
int entity::getHealth()
{
    return health;
}

//implementing set attack function
void entity::modifyAttack(int eattack)
{
    attack = eattack;
}
//get attack function
int entity::getAttack()
{
    return attack;
}

//entity deconstructor
entity::~entity(){}
