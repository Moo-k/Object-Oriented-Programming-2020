//arrow.h
#ifndef ARROW_H
#define ARROW_H

#include "cell.h"
#include "entity.h"
#include <string>
#include <iostream>

class arrow: public entity
{
public:
    arrow();
    virtual int getAttack();
    virtual int getHealth();
    virtual void modifyAttack(int eattack);
    ~arrow();
};

#endif // ARROW_H
