//arrow.cpp
#include "cell.h"
#include "entity.h"
#include "arrow.h"
#include <string>
#include <iostream>

using namespace std;

//implementing default arrow constructor
arrow::arrow():entity()
{
    health=1;
    attack=1;
}

int arrow::getAttack()
{
    return attack;
}

int arrow::getHealth()
{
    return health;
}

void arrow::modifyAttack(int eattack){
    attack = eattack;
}

//implementing arrow deconstructor
arrow::~arrow()
{
}
