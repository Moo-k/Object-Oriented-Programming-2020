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

char getch(){
	char c;
	system("stty raw");
	c = getchar();
	system("stty sane");
	return(c);
}

int kbhit(void)
{
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
}

#endif

void random5rows(vector<vector<cell>> &vec, int startingrow){
  uniform_int_distribution<int> d(0, 2);
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
    default:
      cerr << "rand5 Error" << endl;
      break;
  }
}

int main(void){
  vector<cell> emptyrow(10,cell('E'));
  vector<vector<cell>> map(15,emptyrow);
  for (int i = 0; i < 3; i++){
    random5rows(map,i*5);
  }
  int playerrowcoord = 0;
  int playercolcoord = 4;
  //unsigned int coins = 0;
  unsigned int score = 0;
  unsigned int playerhealth = 10;
  unsigned int playerattack = 2;
  map[playerrowcoord][playercolcoord].setstate('P');
  for (int i = 14; i >= 0; i--){
    for (int j = 0; j < 10; j++){
      map[i][j].printcell();
    }
    cout << endl;
  }
  cout << "Score: " << score << " Health: " << playerhealth << " Attack: " << playerattack << endl;
  bool playing = true;
  char dir = '\0';
  while (playing == true){
    dir = getch();
    cout << string(50,'\n');
    switch(dir){
      case 'w':
        switch(map[playerrowcoord+1][playercolcoord].getstate()){
          case 'W':
            break;
          case 'E':
            map[playerrowcoord][playercolcoord].setstate('E');
            playerrowcoord+=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            score++;
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
            score+=2;
            map[playerrowcoord][playercolcoord].setstate('E');
            playerrowcoord+=1;
            map[playerrowcoord][playercolcoord].setstate('P');
            break;
        }
        break;
      case 'a':
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
      case 's':
        if(playerrowcoord == 0){
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
      case 'd':
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
    for (int i = 14; i >= 0; i--){
      for (int j = 0; j < 10; j++){
        map[i][j].printcell();
      }
      cout << endl;
    }
    cout << "Score: " << score << " Health: " << playerhealth << " Attack: " << playerattack << endl;
  }
}
