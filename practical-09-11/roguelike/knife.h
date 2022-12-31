//knife.h
#ifndef KNIFE_H
#define KNIFE_H

#include "cell.h"
#include "item.h"
#include <string>
#include <iostream>

class knife: public item
{
public:
    knife();
    virtual int getHealth();
    virtual int getAttack();
    ~knife();
};

#endif //KNIFE.CPP
