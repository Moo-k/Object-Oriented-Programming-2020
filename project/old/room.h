#ifndef _ROOM_H
#define _ROOM_H
#include <iostream>
using namespace std;
#include <string>
#include "cell.h"
#include "player.h"

class room{
public:
	room();
	room(int acols, int arows);
	int cols;
	int rows;
	cell **cellarray;
	cell **getroom();
	~room();
};
