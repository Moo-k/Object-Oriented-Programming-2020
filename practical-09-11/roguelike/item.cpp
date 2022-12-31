//item.cpp
#include <iostream>
#include <string>
#include "cell.h"
#include "item.h"

using namespace std;

//item default constructor
item::item()
{
    health=0;
    attack=0;
}

//item constructor taking ihealth and iattack as parameter
item::item(int ihealth, int iattack)
{
    health = ihealth;
    attack = iattack;
}

//implementing set health function
void item::modifyHealth(int ihealth)
{
    health = ihealth;
}
//get health function
int item::getHealth()
{
    return health;
}

//implementing set attack function
void item::modifyAttack(int iattack)
{
    attack = iattack;
}
//get attack function
int item::getAttack()
{
    return attack;
}

//item deconstructor
item::~item(){}
