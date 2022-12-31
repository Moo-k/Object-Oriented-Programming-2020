#include <iostream>
using namespace std;
#include <string>
#include "cellnp.h"

int main(void){
  const int rows = 20;
  const int cols = 40;
	cell room[rows][cols];
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      room[i][j].setrowcoord(i);
      room[i][j].setcolcoord(j);
      room[i][j].setprintout('.');
    }
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 13; j++){
      room[i][j].setstate("blackjack");
      if (i == 0 | j == 0| i == 4 || j == 12){
        room[i][j].setprintout('X');
      } else{
        room[i][j].setprintout(' ');
      }
    }
  }
  room[2][2].setprintout('B');
  room[2][3].setprintout('L');
  room[2][4].setprintout('A');
  room[2][5].setprintout('C');
  room[2][6].setprintout('K');
  room[2][7].setprintout('J');
  room[2][8].setprintout('A');
  room[2][9].setprintout('C');
  room[2][10].setprintout('K');
	
  bool playing = true;
  int currplayerrowcoord = rows;
  int currplayercolcoord = cols/2;
  room[currplayerrowcoord][currplayercolcoord].setstate("Player");
  room[currplayerrowcoord][currplayercolcoord].setprintout('P');
  char dir = '\0';
  while(playing){
    cin >> dir;
    room[currplayerrowcoord][currplayercolcoord].setstate("Tile");
  room[currplayerrowcoord][currplayercolcoord].setprintout('.');
  switch(dir){
    case 'w':
      currplayerrowcoord--;
      break;
    case 'a':
      currplayercolcoord--;
      break;
    case 's':
      currplayerrowcoord++;
      break;
    case 'd':
      currplayercolcoord++;
      break;
  }
  room[currplayerrowcoord][currplayercolcoord].setstate("Player");
  room[currplayerrowcoord][currplayercolcoord].setprintout('O');
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        room[i][j].printcell();
      }
      cout << endl;
    }
  }
}
