#include <iostream>
using namespace std;
#include <string>
#include "cellnp.h"

extern bool blackjack();
extern bool pokies();
extern bool roulette();
extern bool baccarat();

int main(void){
  const int rows = 20;
  const int cols = 40;
	cell room[rows][cols];
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      room[i][j].setrowcoord(i);
      room[i][j].setcolcoord(j);
      room[i][j].setprintout('.');
      room[i][j].setstate('T');
    }
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 14; j++){
      room[i][j].setstate('B');
      if (i == 0 | j == 0| i == 4 || j == 13){
        room[i][j].setprintout('X');
      } else{
        room[i][j].setprintout(' ');
      }
    }
  }
  room[2][3].setprintout('B');
  room[2][4].setprintout('A');
  room[2][5].setprintout('C');
  room[2][6].setprintout('C');
  room[2][7].setprintout('A');
  room[2][8].setprintout('R');
  room[2][9].setprintout('A');
  room[2][10].setprintout('T');

  for (int i = 0; i < 5; i++){
    for (int j = 14; j < 28; j++){
      room[i][j].setstate('R');
      if (i == 0 | j == 14| i == 4 || j == 27){
        room[i][j].setprintout('X');
      } else{
        room[i][j].setprintout(' ');
      }
    }
  }
  room[2][17].setprintout('R');
  room[2][18].setprintout('O');
  room[2][19].setprintout('U');
  room[2][20].setprintout('L');
  room[2][21].setprintout('E');
  room[2][22].setprintout('T');
  room[2][23].setprintout('T');
  room[2][24].setprintout('E');

  for (int i = 0; i < 5; i++){
    for (int j = 28; j < 40; j++){
      room[i][j].setstate('K');
      if (i == 0 | j == 28| i == 4 || j == 39){
        room[i][j].setprintout('X');
      } else{
        room[i][j].setprintout(' ');
      }
    }
  }
  room[2][31].setprintout('P');
  room[2][32].setprintout('O');
  room[2][33].setprintout('K');
  room[2][34].setprintout('I');
  room[2][35].setprintout('E');
  room[2][36].setprintout('S');
	
  for (int i = 5; i < 16; i++){
    for (int j = 0; j < 7; j++){
      room[i][j].setstate('J');
      if (i == 5  | j == 0| i == 15 || j == 6){
        room[i][j].setprintout('X');
      } else{
        room[i][j].setprintout(' ');
      }
    }
  }
  room[6][3].setprintout('B');
  room[7][3].setprintout('L');
  room[8][3].setprintout('A');
  room[9][3].setprintout('C');
  room[10][3].setprintout('K');
  room[11][3].setprintout('J');
  room[12][3].setprintout('A');
  room[13][3].setprintout('C');
  room[14][3].setprintout('K');

  bool playing = true;
  int currplayerrowcoord = rows - 1;
  int currplayercolcoord = cols/2;
  room[currplayerrowcoord][currplayercolcoord].setstate('P');
  room[currplayerrowcoord][currplayercolcoord].setprintout('O');
  char dir = '\0';
  while(playing){
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        room[i][j].printcell();
      }
      cout << endl;
    }
    cin >> dir;
    room[currplayerrowcoord][currplayercolcoord].setstate('T');
    room[currplayerrowcoord][currplayercolcoord].setprintout('.');
    switch(dir){
      case 'w':
        switch (room[currplayerrowcoord-1][currplayercolcoord].getstate()){
          case 'T':
            currplayerrowcoord -= 1;
            break;
          case 'J':
            blackjack();
            break;
          case 'K':
            pokies();
            break;
          case 'B':
            baccarat();
            break;
          case 'R':
            roulette();
            break;
          default:
            cout << "Invalid input." << endl;
            break;
        }
        break;
      case 'a':
        switch (room[currplayerrowcoord][currplayercolcoord-1].getstate()){
          case 'T':
            currplayercolcoord -= 1;
            break;
          case 'J':
            blackjack();
            break;
          case 'K':
            pokies();
            break;
          case 'B':
            baccarat();
            break;
          case 'R':
            roulette();
            break;
          default:
            cout << "Invalid input." << endl;
            break;
        }
        break;
      case 's':
        switch (room[currplayerrowcoord+1][currplayercolcoord].getstate()){
          case 'T':
            currplayerrowcoord += 1;
            break;
          case 'J':
            blackjack();
            break;
          case 'K':
            pokies();
            break;
          case 'B':
            baccarat();
            break;
          case 'R':
            roulette();
            break;
          default:
            cout << "Invalid input." << endl;
            break;
        }
        break;
      case 'd':
        switch (room[currplayerrowcoord][currplayercolcoord+1].getstate()){
          case 'T':
            currplayercolcoord += 1;
            break;
          case 'J':
            blackjack();
            break;
          case 'K':
            pokies();
            break;
          case 'B':
            baccarat();
            break;
          case 'R':
            roulette();
            break;
          default:
            cout << "Invalid input." << endl;
            break;
        }
        break;
    }
    room[currplayerrowcoord][currplayercolcoord].setstate('P');
    room[currplayerrowcoord][currplayercolcoord].setprintout('O');
  }
}
