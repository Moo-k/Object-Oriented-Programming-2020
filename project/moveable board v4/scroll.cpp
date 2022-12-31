#include <iostream>
using namespace std;
#include <string>
#include <random>
#include "cell.h"
//#include "zombie.h"
//#include "skeleton.h"
#ifdef _WIN32
	#include <conio.h>
#else
	#include <cstdlib>
	#include <unistd.h>
  #include <termios.h>
  #include <fcntl.h>

char getch(){ // getch from conio.h in linux
	char c;
	system("stty raw");
	c = getchar();
	system("stty sane");
	return(c);
}

/*int kbhit(void){ // kbhit from conio.h in linux /// unneeded ///
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}*/

#endif

void random5rows(vector<vector<cell>> &vec, int startingrow){ // line 52 - 217: presets of 5 rows each for random world generation
  uniform_int_distribution<int> d(0, 6);
  random_device rd1;
  int presetnum = d(rd1);
  switch(presetnum){
    case 0:
      for (int i = 0; i < 4; i++){
        vec[startingrow][i].setstate('W');
      }
      for (int i = 6; i < 10; i++){
        vec[startingrow][i].setstate('W');
      }
      for (int i = 1; i < 3; i++){
        vec[startingrow+2][i].setstate('W');
      }
      for (int i = 7; i < 9; i++){
        vec[startingrow+2][i].setstate('W');
      }
      vec[startingrow+1][3].setstate('C');
      vec[startingrow+1][6].setstate('C');
      vec[startingrow+2][3].setstate('C');
      vec[startingrow+2][6].setstate('C');
      vec[startingrow+2][0].setstate('C');
      vec[startingrow+2][9].setstate('C');
      vec[startingrow+3][0].setstate('C');
      vec[startingrow+3][1].setstate('C');
      vec[startingrow+3][2].setstate('W');
      vec[startingrow+3][7].setstate('W');
      vec[startingrow+3][8].setstate('C');
      vec[startingrow+3][9].setstate('C');
      for (int i = 0; i < 3; i++){
        vec[startingrow+4][i].setstate('W');
      }
      for (int i = 7; i < 10; i++){
        vec[startingrow+4][i].setstate('W');
      }
      break;
    case 1:
      for (int i = startingrow; i < startingrow+4; i++){
        for (int j = 0; j < 10; j++){
          if (i%5 == j | i%5 == j+1 | i%5 + 4 == j | i%5 + 5 == j){
            vec[i][j].setstate('W');
          }
        }
      }
      vec[startingrow][9].setstate('W');
      vec[startingrow][3].setstate('C');
      vec[startingrow][6].setstate('C');
      vec[startingrow+1][4].setstate('C');
      vec[startingrow+1][7].setstate('C');
      vec[startingrow+2][5].setstate('C');
      vec[startingrow+2][8].setstate('C');
      vec[startingrow+3][1].setstate('C');
      vec[startingrow+3][6].setstate('C');
      vec[startingrow+4][2].setstate('C');
      vec[startingrow+4][7].setstate('C');
      break;
    case 2:
      for (int i = startingrow; i < startingrow+4; i++){
        for (int j = 0; j < 10; j++){
          if (i%5 == 10-j | i%5 == 9-j | i%5 == 5-j | i%5 == 4-j){
            vec[i][j].setstate('W');
          }
        }
      }
      vec[startingrow][0].setstate('W');
      vec[startingrow][3].setstate('C');
      vec[startingrow][6].setstate('C');
      vec[startingrow+1][2].setstate('C');
      vec[startingrow+1][5].setstate('C');
      vec[startingrow+2][1].setstate('C');
      vec[startingrow+2][4].setstate('C');
      vec[startingrow+3][3].setstate('C');
      vec[startingrow+3][8].setstate('C');
      vec[startingrow+4][2].setstate('C');
      vec[startingrow+4][7].setstate('C');
      break;
    case 3:
      for (int i = 0; i < 4; i++){
        vec[startingrow+1+i][0].setstate('W');
      }
      vec[startingrow+1][1].setstate('W');
      for (int i = 0; i < 3; i++){
        vec[startingrow+1+i][2].setstate('W');
      }
      vec[startingrow+3][3].setstate('W');
      for (int i = 0; i < 3; i++){
        vec[startingrow+1+i][4].setstate('W');
      }
      for (int i = 0; i < 4; i++){
        vec[startingrow+1][6+i].setstate('W');
        vec[startingrow+3][6+i].setstate('W');
      }
      for (int i = 0; i < 3; i++){
        vec[startingrow][7+i].setstate('C');
        vec[startingrow+2][7+i].setstate('C');
      }
      vec[startingrow+1][3].setstate('C');
      vec[startingrow+2][3].setstate('C');
      vec[startingrow+2][1].setstate('C');
      vec[startingrow+3][1].setstate('C');
      break;
    case 4:
      for (int i = 0; i < 4; i++){
        vec[startingrow+1][i].setstate('W');
        vec[startingrow+3][i].setstate('W');
        vec[startingrow+1+i][9].setstate('W');
      }
      for (int i = 0; i < 3; i++){
        vec[startingrow][i].setstate('C');
        vec[startingrow+2][i].setstate('C');
        vec[startingrow+1+i][5].setstate('W');
        vec[startingrow+1+i][7].setstate('W');
      }
      vec[startingrow+3][6].setstate('W');
      vec[startingrow+1][8].setstate('W');
      vec[startingrow+1][6].setstate('C');
      vec[startingrow+2][6].setstate('C');
      vec[startingrow+2][8].setstate('C');
      vec[startingrow+3][8].setstate('C');
      break;
    case 5:
      for (int i = 0; i < 3; i++){
        vec[startingrow+2+i][0].setstate('W');
        vec[startingrow+i][9].setstate('W');
        vec[startingrow+3][2+i].setstate('W');
        vec[startingrow+1][5+i].setstate('W');
      }
      for (int i = 0; i < 2; i++){
        vec[startingrow+2+i][1].setstate('C');
        vec[startingrow+1+i][8].setstate('C');
        vec[startingrow+2][3+i].setstate('C');
        vec[startingrow+2][5+i].setstate('C');
      }
      vec[startingrow+1][1].setstate('W');
      vec[startingrow+2][2].setstate('W');
      vec[startingrow+2][7].setstate('W');
      vec[startingrow+3][8].setstate('W');
      vec[startingrow+1][2].setstate('C');
      vec[startingrow+3][7].setstate('C');
      break;
    case 6:
      for (int i = 0; i < 3; i++){
        vec[startingrow+i][0].setstate('W');
        vec[startingrow+2+i][9].setstate('W');
        vec[startingrow+1][2+i].setstate('W');
        vec[startingrow+3][5+i].setstate('W');
      }
      for (int i = 0; i < 2; i++){
        vec[startingrow+1+i][1].setstate('C');
        vec[startingrow+2+i][8].setstate('C');
        vec[startingrow+2][3+i].setstate('C');
        vec[startingrow+2][5+i].setstate('C');
      }
      vec[startingrow+3][1].setstate('W');
      vec[startingrow+2][2].setstate('W');
      vec[startingrow+2][7].setstate('W');
      vec[startingrow+1][8].setstate('W');
      vec[startingrow+3][2].setstate('C');
      vec[startingrow+1][7].setstate('C');
      break;
    default:
      cerr << "World Generation Error" << endl;
      break;
  }
}

int main(void){
  vector<cell> emptyrow(10,cell('E')); // define an empty row as 10 cells with state 'E'
  vector<vector<cell>> map(15,emptyrow); // create 2d vector of 15 rows (10 cols)
  for (int i = 0; i < 3; i++){ // generate terrain for the first 15x10 (5 rows at a time x3)
    random5rows(map,i*5);
  }
  int playerrowcoord = 0;
  int playercolcoord = 4; // player starting coords, overwriting world gen
  //unsigned int coins = 0;
  unsigned int score = 0;
  unsigned int playerhealth = 10;
  unsigned int playerattack = 2; // initialise player stats, coins = 1 score (scale health and attack to enemies defeated later)
  map[playerrowcoord][playercolcoord].setstate('P');
  int botrow = 0; // last row printed (0 is at the bottom)
  cout << string(50,'\n'); // spacer
  for (int i = botrow+9; i >= botrow; i--){
    for (int j = 0; j < 10; j++){
      map[i][j].printcell();
    }
    cout << endl;
  }
  cout << "Score: " << score << " Health: " << playerhealth << " Attack: " << playerattack << endl; // print player stats below map
  bool playing = true; // while loop statement
  char dir = '\0'; // initialise direction
  while (playing == true){
    dir = getch(); // wait for user input for movement
    cout << string(50,'\n'); // spacer
    switch(dir){
      case 'w': // if w is pressed
        switch(map[playerrowcoord+1][playercolcoord].getstate()){ // check state of cell ahead
          case 'W': // if wall do nothing
            break;
          case 'E': // if empty move forward, set behind to empty, and increase score
            map[playerrowcoord][playercolcoord].setstate('E');
            playerrowcoord+=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            if(playerrowcoord > botrow+2){ // if more than 2 rows above botrow, move botrow up (means player will never be more than 2 rows above bottom) (also means only 15 rows need to be kept at all times)
              botrow++;
            }
            score++;
            break;
          case 'S':
            cout << "Attacked Skeleton" << endl;
            break;
            // 2 cell ranged attack?
            // when defeated, turn into coin
            // add health and attack for player?
          case 'Z':
            cout << "Attacked Zombie" << endl;
            break;
            // melee attack
            // zombie revives after 5 moves?
            // when defeated, turn into coin
            // add health and attack for player?
          case 'C': // other items can be added: health pots, attack buffs(turn based/perm)?
            //coins++;
            score+=2;
            map[playerrowcoord][playercolcoord].setstate('E');
            playerrowcoord+=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            if (playerrowcoord > botrow+2){
              botrow++;
            }
            break;
        }
        break;
      case 'a': // cases for moving left
        switch(map[playerrowcoord][playercolcoord-1].getstate()){
          case 'W':
            break;
          case 'E':
            map[playerrowcoord][playercolcoord].setstate('E');
            playercolcoord-=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            break;
          case 'S':
            cout << "Attacked Skeleton" << endl;
            break;
            // 2 cell ranged attack
            // when defeated, turn into coin
          case 'Z':
            cout << "Attacked Zombie" << endl;
            break;
            // melee attack
            // zombie revives after 5 moves?
            // when defeated, turn into coin
          case 'C':
            //coins++;
            score++;
            map[playerrowcoord][playercolcoord].setstate('E');
            playercolcoord-=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            break;
        }
        break;
      case 's': // cases for moving down
        if(playerrowcoord == botrow){ // if trying to move out of bounds, drop dead
          cout << "YOU DIED" << endl;
          playing = false;
          break;
        } else{
          switch(map[playerrowcoord-1][playercolcoord].getstate()){
            case 'W':
              break;
            case 'E':
              score--;
              map[playerrowcoord][playercolcoord].setstate('E');
              playerrowcoord-=1;
              map[playerrowcoord][playercolcoord].setstate('P');
              break;
            case 'S':
              cout << "Attacked Skeleton" << endl;
              break;
              // 2 cell ranged attack
              // when defeated, turn into coin
            case 'Z':
              cout << "Attacked Zombie" << endl;
              break;
              // melee attack
              // zombie revives after 5 moves?
              // when defeated, turn into coin
            case 'C':
              //coins++;
              map[playerrowcoord][playercolcoord].setstate('E');
              playerrowcoord-=1;
              map[playerrowcoord][playercolcoord].setstate('P');
              break;
          }
          break;
        }
      case 'd': // cases for moving right
        switch(map[playerrowcoord][playercolcoord+1].getstate()){
          case 'W':
            break;
          case 'E':
            map[playerrowcoord][playercolcoord].setstate('E');
            playercolcoord+=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            break;
          case 'S':
            cout << "Attacked Skeleton" << endl;
            break;
            // 2 cell ranged attack
            // when defeated, turn into coin
          case 'Z':
            cout << "Attacked Zombie" << endl;
            break;
            // melee attack
            // zombie revives after 5 moves?
            // when defeated, turn into coin
          case 'C':
            //coins++;
            score++;
            map[playerrowcoord][playercolcoord].setstate('E');
            playercolcoord+=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            break;
        }
        break;
    }
    if (botrow > 4){ // if more than 4 above botrow, delete memory of last 5 rows (0-4), then add 5 more empty rows to the end of map and randomly generate terrain
      map.erase(map.begin(),map.begin()+5);
      for (int i = 0; i < 5; i++){
        map.push_back(emptyrow);
      }
      random5rows(map,10);
      botrow = 0; // set botrow back to 0 and subtract 5 from player row coordinates
      playerrowcoord -= 5;
    }
    for (int i = botrow+9; i >= botrow; i--){ // print shown map
      for (int j = 0; j < 10; j++){
        map[i][j].printcell();
      }
      cout << endl;
    }
    cout << "Score: " << score << " Health: " << playerhealth << " Attack: " << playerattack << endl;
  }
}
