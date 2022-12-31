//apple.h
#ifndef APPLE_H
#define APPLE_H

#include "cell.h"
#include "item.h"
#include <string>
#include <iostream>

class apple: public item
{
public:
    apple();
    virtual int getHealth();
    virtual int getAttack();
    ~apple();
};

#endif //APPLE.CPP
