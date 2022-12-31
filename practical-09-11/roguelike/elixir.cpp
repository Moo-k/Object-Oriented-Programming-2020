//elixir.cpp
#include "cell.h"
#include "item.h"
#include "elixir.h"
#include <string>
#include <iostream>

using namespace std;

//implementing default elixir constructor
elixir::elixir():item()
{
    health=1;
    attack=1;
}

int elixir::getAttack()
{
    return attack;
}

int elixir::getHealth()
{
    return health;
}

//implementing elixir deconstructor
elixir::~elixir()
{
}
