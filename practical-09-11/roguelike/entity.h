//entity.h
#ifndef ENTITY_H
#define ENTITY_H
#include "cell.h"
#include <string>

class entity : public cell
{
public:
    entity();
    entity(int erow, int ecol, int ehealth,int eattack);
    virtual void modifyRowCoord(int erow);
    virtual int getRowCoord();
    virtual void modifyColCoord(int ecol);
    virtual int getColCoord();
    virtual void modifyHealth(int ehealth);
    virtual int getHealth();
    virtual void modifyAttack(int eattack);
    virtual int getAttack();
    ~entity();
    int rowCoord;
    int colCoord;
    int health;
    int attack;
};

#endif //ENTITY_H
