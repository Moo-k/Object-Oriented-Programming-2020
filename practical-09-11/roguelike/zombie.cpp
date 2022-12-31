//zombie.cpp
#include <string>
#include <iostream>
#include "zombie.h"
#include "entity.h"
using namespace std;

//implementing zombie default constructor
zombie::zombie()
{
    health = 0;
    attack = 0;
}
//implementing zombie constructor(Parameter: health+attack)
zombie::zombie(int zhealth, int zattack)
{
    health = zhealth;
    attack = zattack;
}

//implementing zombie health function
void zombie::modifyHealth(int zhealth)
{
    health = zhealth;
}
//get zombie health
int zombie::getHealth()
{
    return health;
}

//implementing zombie attack function
void zombie::modifyAttack(int zattack)
{
    attack = zattack;
}
//get zombie attack function
int zombie::getAttack()
{
    return attack;
}

void zombie::modifyRowCoord(int zrow){
    rowCoord = zrow;
}

int zombie::getRowCoord(){
    return rowCoord;
}

void zombie::modifyColCoord(int zcol){
    colCoord = zcol;
}

int zombie::getColCoord(){
    return colCoord;
}

//zombie destructor
zombie::~zombie()
{
}
