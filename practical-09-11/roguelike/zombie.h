//Zombie.h
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "entity.h"
#include "player.h"
#include <vector>
using namespace std;

class zombie: public entity
{
public:
    zombie();
    zombie(int zhealth, int zattack);
    virtual void modifyHealth(int zhealth);
    virtual int getHealth();
    virtual void modifyAttack(int zattack);
    virtual int getAttack();
    virtual void modifyRowCoord(int zrow);
    virtual int getRowCoord();
    virtual void modifyColCoord(int zcol);
    virtual int getColCoord();
    ~zombie();
};
#endif //ZOMBIE_H
