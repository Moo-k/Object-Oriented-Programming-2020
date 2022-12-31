//skeleton.h
#ifndef SKELETON_H
#define SKELETON_H
#include "entity.h"
#include <string>
using namespace std;

class skeleton : public entity
{
public:
    skeleton();
    skeleton(int shealth, int sattack);
    virtual void modifyHealth(int shealth);
    virtual int getHealth();
    virtual void modifyAttack(int sattack);
    virtual int getAttack();
    ~skeleton();
};
#endif //SKELETON_H
