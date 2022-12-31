//player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "cell.h"
#include "entity.h"
#include <string>
#include <iostream>

class player : public entity
{
public:
    player();
    int score;
    virtual int getAttack();
    virtual void modifyAttack(int pattack);
    virtual int getHealth();
    virtual void modifyHealth(int phealth);
    virtual void modifyRowCoord(int prow);
    virtual int getRowCoord();
    virtual void modifyColCoord(int pcol);
    virtual int getColCoord();
    int getScore();
    void modifyScore(int pscore);
    ~player();
};

#endif //PLAYER_H
