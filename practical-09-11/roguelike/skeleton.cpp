//skeleton.cpp
#include <string>
#include <iostream>
#include "skeleton.h"
#include "entity.h"
using namespace std;

//implementing skeleton default constructor
skeleton::skeleton()
{
    health = 0;
    attack = 0;
}
//implementing skeleton constructor(Parameter: health+attack)
skeleton::skeleton(int shealth, int sattack)
{
    health = shealth;
    attack = sattack;
}

//implementing skeleton health function
void skeleton::modifyHealth(int shealth)
{
    health = shealth;
}
//get skeleton health
int skeleton::getHealth()
{
    return health;
}

//implementing skeleton attack function
void skeleton::modifyAttack(int sattack)
{
    attack = sattack;
}
//get skeleton attack function
int skeleton::getAttack()
{
    return attack;
}
//skeleton destructor
skeleton::~skeleton()
{
}
