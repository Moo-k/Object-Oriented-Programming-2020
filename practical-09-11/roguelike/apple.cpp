//apple.cpp
#include "cell.h"
#include "item.h"
#include "apple.h"
#include <string>
#include <iostream>

using namespace std;

//implementing default apple constructor
apple::apple():item()
{
    health=1;
    attack=0;
}

//implementing apple getHealth
int apple::getHealth()
{
    return health;
}
//implementing apple getAttack
int apple::getAttack()
{
    return attack;
}

//implementing apple deconstructor
apple::~apple()
{
}
