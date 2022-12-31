//elixir.h
#ifndef ELIXIR_H
#define ELIXIR_H

#include "cell.h"
#include "item.h"
#include <string>
#include <iostream>

class elixir: public item
{
public:
    elixir();
    virtual int getAttack();
    virtual int getHealth();
    ~elixir();
};

#endif //ELIXIR.CPP
