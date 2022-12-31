//item.h
#ifndef ITEM_H
#define ITEM_H
#include "cell.h"
#include <string>

class item : public cell
{
public:
    item();
    item(int ihealth,int iattack);
    virtual void modifyHealth(int ihealth);
    virtual int getHealth();
    virtual void modifyAttack(int iattack);
    virtual int getAttack();
    ~item();

    int health;
    int attack;
};

#endif //ITEM_H
