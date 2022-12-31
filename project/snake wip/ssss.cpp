#include <iostream>
using namespace std;
#include <string>
#include "scell.h"
/*#ifdef _WIN32
	#include <conio.h>
#else*/
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

int main(void){
  int xsize = 0;
  int ysize = 0;
  int difficulty = 0;
  unsigned int timer = 0;

  cout << "Enter size of board (width height):" << endl;
  cin >> xsize >> ysize;

  while (difficulty == 0){
    cout << "Enter difficulty level (1/2/3): " << endl;
    cin >> difficulty;
    switch (difficulty){
      case 1:
        timer = 400000;
        break;
      case 2:
        timer = 300000;
        break;
      case 3:
        timer = 200000;
        break;
      default:
        difficulty = 0;
    }
  }
      

  scell board[ysize][xsize];
  for (int i = 0; i < ysize; i++){
    for (int j = 0; j < xsize; j++){
      if (i == 0 | i == ysize-1 | j == 0 | j == xsize-1){
        board[i][j] = scell(j,i,'W','w');
      } else{
          board[i][j] = scell(j,i,'E','w');
      }
    }
  }
  int headxcoord = xsize/2;
  int headycoord = ysize/2;
  board[headycoord][headxcoord].setstate('H');
  int tailxcoord = headxcoord;
  int tailycoord = headycoord + 1;
  board[tailycoord][tailxcoord].setstate('T');

  bool gameloop = true;
  char dir = '\0';
  while (gameloop){
    // cout << string(50,'\n');

    if(kbhit()){
      dir = getch();
      //gameloop = move(dir,headxcoord,headycoord,tailxcoord,tailycoord);
    }

    switch (dir){
    case 'w':
      if (board[headycoord - 1][headxcoord].getstate() == 'T' | board[headycoord - 1][headxcoord].getstate() == 'B' | board[headycoord - 1][headxcoord].getstate() == 'W'){
        gameloop = false;
      } else if (board[headycoord - 1][headxcoord].getstate() == 'F'){
        board[headycoord][headxcoord].setstate('B');
        headycoord -= 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('w');
        gameloop = true;
      } else{
        board[headycoord][headxcoord].setstate('B');
        headycoord -= 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('w');
        board[tailycoord][tailxcoord].setstate('E');
        switch (board[tailycoord][tailxcoord].getdirection()){
          case 'w':
            board[tailycoord - 1][tailxcoord].setstate('T');
            break;
          case 'a':
            board[tailycoord][tailxcoord - 1].setstate('T');
            break;
          case 's':
            board[tailycoord + 1][tailxcoord].setstate('T');
            break;
          case 'd':
            board[tailycoord][tailxcoord + 1].setstate('T');
            break;
        }
        gameloop = true;
      }
    case 'a':
      if (board[headycoord][headxcoord - 1].getstate() == 'T' | board[headycoord][headxcoord - 1].getstate() == 'B' | board[headycoord][headxcoord - 1].getstate() == 'W'){
        gameloop = false;
      } else if (board[headycoord][headxcoord - 1].getstate() == 'F'){
        board[headycoord][headxcoord].setstate('B');
        headxcoord -= 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('a');
        gameloop = true;
      } else{
        board[headycoord][headxcoord].setstate('B');
        headxcoord -= 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('a');
        board[tailycoord][tailxcoord].setstate('E');
        switch (board[tailycoord][tailxcoord].getdirection()){
          case 'w':
            board[tailycoord - 1][tailxcoord].setstate('T');
            break;
          case 'a':
            board[tailycoord][tailxcoord - 1].setstate('T');
            break;
          case 's':
            board[tailycoord + 1][tailxcoord].setstate('T');
            break;
          case 'd':
            board[tailycoord][tailxcoord + 1].setstate('T');
            break;
        }
        gameloop = true;
      }
    case 's':
      if (board[headycoord + 1][headxcoord].getstate() == 'T' | board[headycoord + 1][headxcoord].getstate() == 'B' | board[headycoord + 1][headxcoord].getstate() == 'W'){
        gameloop = false;
      } else if (board[headycoord + 1][headxcoord].getstate() == 'F'){
        board[headycoord][headxcoord].setstate('B');
        headycoord += 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('s');
        gameloop = true;
      } else{
        board[headycoord][headxcoord].setstate('B');
        headxcoord += 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('s');
        board[tailycoord][tailxcoord].setstate('E');
        switch (board[tailycoord][tailxcoord].getdirection()){
          case 'w':
            board[tailycoord - 1][tailxcoord].setstate('T');
            break;
          case 'a':
            board[tailycoord][tailxcoord - 1].setstate('T');
            break;
          case 's':
            board[tailycoord + 1][tailxcoord].setstate('T');
            break;
          case 'd':
            board[tailycoord][tailxcoord + 1].setstate('T');
            break;
        }
        gameloop = true;
      }
    case 'd':
      if (board[headycoord][headxcoord + 1].getstate() == 'T' | board[headycoord][headxcoord + 1].getstate() == 'B' | board[headycoord][headxcoord + 1].getstate() == 'W'){
        gameloop = false;
      } else if (board[headycoord][headxcoord + 1].getstate() == 'F'){
        board[headycoord][headxcoord].setstate('B');
        headxcoord += 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('d');
        gameloop = true;
      } else{
        board[headycoord][headxcoord].setstate('B');
        headxcoord += 1;
        board[headycoord][headxcoord].setstate('H');
        board[headycoord][headxcoord].setdirection('d');
        board[tailycoord][tailxcoord].setstate('E');
        switch (board[tailycoord][tailxcoord].getdirection()){
          case 'w':
            board[tailycoord - 1][tailxcoord].setstate('T');
            break;
          case 'a':
            board[tailycoord][tailxcoord - 1].setstate('T');
            break;
          case 's':
            board[tailycoord + 1][tailxcoord].setstate('T');
            break;
          case 'd':
            board[tailycoord][tailxcoord + 1].setstate('T');
            break;
        }
        gameloop = true;
      }
  }
  gameloop = true;

    for (int i = 0; i < ysize; i++){
      for (int j = 0; j < xsize; j++){
        board[i][j].printcell();
      }
      cout << endl;
    }

    if (gameloop == false){
      cout << "GAME OVER!" << endl;
    }

    usleep(timer);
  }
}
