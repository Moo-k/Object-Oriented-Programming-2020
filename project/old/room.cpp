#include <iostream>
using namespace std;
#include <string>
#include "room.h"
#include "player.h"
#include "cell.h"

room();

room(int acols, int arows){
	cols = acols;
	rows = arows;
	for (int i = 0; i < rows; i++){
		cellarray[i] = new cell*[cols];
	}
};


cell **getroom();

~room();
