//apple.cpp
#include "cell.h"
#include "item.h"
#include "knife.h"
#include <string>
#include <iostream>

using namespace std;

//implementing default knife constructor
knife::knife():item()
{
    health=0;
    attack=1;
}

//implementing knife getHealth
int knife::getHealth()
{
    return health;
}
//implementing knife getAttack
int knife::getAttack()
{
    return attack;
}

//implementing knife deconstructor
knife::~knife()
{
}
