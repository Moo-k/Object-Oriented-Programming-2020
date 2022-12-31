#include <iostream>
using namespace std;
#include <string>
#include <random>
#include "cell.h"
#include "zombie.h"
#include "skeleton.h"
#include "item.h"
#include "knife.h"
#include "elixir.h"
#include "apple.h"
#include "entity.h"
#include "player.h"
#include "arrow.h"
#ifdef _WIN32
	#include <conio.h>
#else
	#include <cstdlib>
	#include <unistd.h>
  #include <termios.h>
  #include <fcntl.h>
  char getch(); // declaration of getch from conio.h
#endif
void clearscreen(); // declaration of function to clear terminal
void random5rows(vector<vector<cell>> &vec, int startingrow); // declaration of world gen, infinite

//Main function
int main(void){
  // create player
  player p1;
  //map implementation
  vector<cell> emptyrow(10,cell('E')); // define an empty row as 10 cells with state 'E'
  vector<vector<cell>> map(15,emptyrow); // create 2d vector of 15 rows (10 cols)
  vector<entity> mobs;
  for (int i = 0; i < 3; i++){ // generate terrain for the first 15x10 (5 rows at a time x3)
    random5rows(map,i*5);
  }
  //zombie implementation
  zombie z1(5,2);
  z1.setState('Z');

  //skeleton implementation
  skeleton s1(3,2);
  s1.setState('S');

  //elixir implementation
  elixir e1;
  e1.setState('X');

  //apple implementation
  apple a1;
  a1.setState('A');

  //knife implementation
  knife k1;
  k1.setState('K');

  //player implementation
  int playerRowCoord = 0;
  int playerColCoord = 4; // player starting coords, overwriting world gen
  map[playerRowCoord][playerColCoord].setState('P');
  int botrow = 0; // last row printed (0 is at the bottom)
  clearscreen(); // clear screen
  
  //introductory to game.
  cout << "Welcome to Cov-one-niner" << endl;
  cout << "'w'-move forward, 's' move backwards,'a'move left, 'd' move right" << endl;
  cout << "W=Wall, C=Coins, P=Player" << endl;
  cout << "Every 10 coins collected gives you 1 attack and 1 health" << endl;

/* SIGN IN SIGN OUT
  cout << "Are you a new player(N) or existing player(E)?" << endl; //asks if they are a new or existig player
					cin >> input; //takes in their input

					if(input == 'N' || input == 'n'){ //if they are new
						user.info = create(); //creates new account info
						save(user); //saves the player
						players.push_back(user); //pushes the player on the vector
					}
					else if(input == 'E' || input == 'e'){ //if they are a existing player
						user.info = load(); //loads their account info
						players.push_back(user); //pushes them on the stack
					}
*/

  //print cells of game
  for (int i = botrow+9; i >= botrow; i--){
    for (int j = 0; j < 10; j++){
      map[i][j].printCell();
    }
    cout << endl;
  }
  cout << "Score: " << p1.getScore() << " Health: " << p1.getHealth() << " Attack: " << p1.getAttack() << endl; // print player stats
  bool playing = true; // while loop statement
  char dir = '\0'; // initialise direction
  while (playing == true){
    dir = getch(); // wait for user input for movement
    cout << string(50,'\n'); // spacer
    //clearscreen();
    switch(dir){
        //MOVE FOWARD
      case 'w': // if w is pressed
        switch(map[playerRowCoord+1][playerColCoord].getState()){ // check state of cell ahead
          case 'W': // if wall do nothing
            break;
          case 'E': // if empty move forward, set behind to empty, and increase score
            map[playerRowCoord][playerColCoord].setState('E');
            playerRowCoord+=1;
            map[playerRowCoord][playerColCoord].setState('P');
            if(playerRowCoord > botrow+2){ // if more than 2 rows above botrow, move botrow up (means player will never be more than 2 rows above bottom) (also means only 15 rows need to be kept at all times)
              botrow++;
            }
            p1.modifyScore(p1.getScore()+1);
            break;
          case 'S':
            cout << "Attacked Skeleton" << endl;
            p1.modifyHealth(p1.getHealth()-s1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            s1.modifyHealth(s1.getHealth()-p1.getAttack());
            if (s1.getHealth()<=0)
            {
                cout << "Skeleton Killed!" << endl;
                p1.modifyScore(p1.getScore()+6);
                map[playerRowCoord][playerColCoord].setState('E');
                playerRowCoord+=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            }
            // 2 cell ranged attack?
            // when defeated, turn into coin
            // add health and attack for player?

          case 'Z':
          // melee attack
            // zombie revives after 5 moves?
            // when defeated, turn into coin
            // add health and attack for player?
            cout << "Attacked Zombie" << endl;
            p1.modifyHealth(p1.getHealth()-z1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            z1.modifyHealth(z1.getHealth()-p1.getAttack());
            if (z1.getHealth()<=0)
            {
                cout << "Zombie Killed!" << endl;
                p1.modifyScore(p1.getScore()+4);
                map[playerRowCoord][playerColCoord].setState('E');
                playerRowCoord+=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            } else {
              cout << "Zombie health left: " << z1.getHealth() << endl;
              break;
            }

          //ELIXR IMPLEMENTATION
          case 'X':
              cout << "Drank elixir: health +1, attack +1" << endl;
              p1.modifyHealth(p1.getHealth()+e1.getHealth());
              p1.modifyAttack(p1.getAttack()+e1.getAttack());
              map[playerRowCoord][playerColCoord].setState('E');
              playerRowCoord+=1;
              map[playerRowCoord][playerColCoord].setState('P');
              break;
          //APPLE IMPLEMENTATION
          case 'A':
          cout << "Ate apple: health +1" << endl;
          p1.modifyHealth(p1.getHealth()+a1.getHealth());
          p1.modifyAttack(p1.getAttack()+a1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerRowCoord+=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          //KNIFE IMPLEMENTATION
          case 'K':
          cout << "Took knife: attack +1" << endl;
          p1.modifyHealth(p1.getHealth()+k1.getHealth());
          p1.modifyAttack(p1.getAttack()+k1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerRowCoord+=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          case 'C': // other items can be added: health pots, attack buffs(turn based/perm)?
            //coins++;
            p1.modifyScore(p1.getScore()+2);
            map[playerRowCoord][playerColCoord].setState('E');
            playerRowCoord+=1;
            map[playerRowCoord][playerColCoord].setState('P');
            if (playerRowCoord > botrow+2){
              botrow++;
            }
            break;
        }
        break;
        
        //MOVE LEFT
      case 'a': // cases for pressing a
        switch(map[playerRowCoord][playerColCoord-1].getState()){
          case 'W':
            break;
          case 'E':
            map[playerRowCoord][playerColCoord].setState('E');
            playerColCoord-=1;
            map[playerRowCoord][playerColCoord].setState('P');
            break;
          case 'S':
            cout << "Attacked Skeleton" << endl;
            p1.modifyHealth(p1.getHealth()-s1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            s1.modifyHealth(s1.getHealth()-p1.getAttack());
            if (s1.getHealth()<=0)
            {
                cout << "Skeleton Killed!" << endl;
                p1.modifyScore(p1.getScore()+5);
                map[playerRowCoord][playerColCoord].setState('E');
                playerColCoord-=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            }
            // 2 cell ranged attack
            // when defeated, turn into coin
          case 'Z':
          // melee attack
          // zombie revives after 5 moves?
          // when defeated, turn into coin
            cout << "Attacked Zombie" << endl;
            p1.modifyHealth(p1.getHealth()-z1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            z1.modifyHealth(z1.getHealth()-p1.getAttack());
            if (z1.getHealth()<=0)
            {
                cout << "Zombie Killed!" << endl;
                p1.modifyScore(p1.getScore()+3);
                map[playerRowCoord][playerColCoord].setState('E');
                playerColCoord-=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            } else {
              cout << "Zombie health left: " << z1.getHealth() << endl;
              break;
            }
          //ELIXIR IMPLEMENTATION
          case 'X':
          cout << "Drank elixir: health +1, attack +1" << endl;
          p1.modifyHealth(p1.getHealth()+e1.getHealth());
          p1.modifyAttack(p1.getAttack()+e1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerColCoord-=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          //APPLE IMPLEMENTATION
          case 'A':
          cout << "Ate apple: health +1" << endl;
          p1.modifyHealth(p1.getHealth()+a1.getHealth());
          p1.modifyAttack(p1.getAttack()+a1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerColCoord-=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          //KNIFE IMPLEMENTATION
          case 'K':
          cout << "Took knife: attack +1" << endl;
          p1.modifyHealth(p1.getHealth()+k1.getHealth());
          p1.modifyAttack(p1.getAttack()+k1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerColCoord-=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          case 'C':
            //coins++;
            p1.modifyScore(p1.getScore()+1);
            map[playerRowCoord][playerColCoord].setState('E');
            playerColCoord-=1;
            map[playerRowCoord][playerColCoord].setState('P');
            break;
        }
        break;
        
        //MOVE DOWN
      case 's': // cases for pressing s
        if(playerRowCoord == botrow){ // if trying to move out of bounds, drop dead
          cout << "YOU DIED" << endl;
          playing = false;
          break;
        } else{
          switch(map[playerRowCoord-1][playerColCoord].getState()){
            case 'W':
              break;
            case 'E':
              p1.modifyScore(p1.getScore()-1);
              map[playerRowCoord][playerColCoord].setState('E');
              playerRowCoord-=1;
              map[playerRowCoord][playerColCoord].setState('P');
              break;
            case 'S':
            cout << "Attacked Skeleton" << endl;
            p1.modifyHealth(p1.getHealth()-s1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            s1.modifyHealth(s1.getHealth()-p1.getAttack());
            if (s1.getHealth()<=0)
            {
                cout << "Skeleton Killed!" << endl;
                p1.modifyScore(p1.getScore()+5);
                map[playerRowCoord][playerColCoord].setState('E');
                playerRowCoord-=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            }
              break;
              // 2 cell ranged attack
              // when defeated, turn into coin
            case 'Z':
              // melee attack
              // zombie revives after 5 moves?
              // when defeated, turn into coin
              cout << "Attacked Zombie" << endl;
              p1.modifyHealth(p1.getHealth()-z1.getAttack());
              if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            } 
            z1.modifyHealth(z1.getHealth()-p1.getAttack());
            if (z1.getHealth()<=0)
            {
                cout << "Zombie Killed!" << endl;
                p1.modifyScore(p1.getScore()+3);
                map[playerRowCoord][playerColCoord].setState('E');
                playerRowCoord-=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            } else {
              cout << "Zombie health left: " << z1.getHealth() << endl;
              break;
            }
            case 'X':
              cout << "Drank elixir: health +1, attack +1" << endl;
              p1.modifyHealth(p1.getHealth()+e1.getHealth());
              p1.modifyAttack(p1.getAttack()+e1.getAttack());
              map[playerRowCoord][playerColCoord].setState('E');
              playerRowCoord-=1;
              map[playerRowCoord][playerColCoord].setState('P');
              break;
            //APPLE IMPLEMENTATION
            case 'A':
            cout << "Ate apple: health +1" << endl;
            p1.modifyHealth(p1.getHealth()+a1.getHealth());
            p1.modifyAttack(p1.getAttack()+a1.getAttack());
            map[playerRowCoord][playerColCoord].setState('E');
            playerRowCoord-=1;
            map[playerRowCoord][playerColCoord].setState('P');
            break;
            //KNIFE IMPLEMENTATION
            case 'K':
            cout << "Took knife: attack +1" << endl;
            p1.modifyHealth(p1.getHealth()+k1.getHealth());
            p1.modifyAttack(p1.getAttack()+k1.getAttack());
            map[playerRowCoord][playerColCoord].setState('E');
            playerRowCoord-=1;
            map[playerRowCoord][playerColCoord].setState('P');
            break;
              
            case 'C':
              //coins++;
              map[playerRowCoord][playerColCoord].setState('E');
              playerRowCoord-=1;
              map[playerRowCoord][playerColCoord].setState('P');
              break;
          }
          break;
        }

        //MOVE RIGHT
      case 'd': // cases for pressing d
        switch(map[playerRowCoord][playerColCoord+1].getState()){
          case 'W':
            break;
          case 'E':
            map[playerRowCoord][playerColCoord].setState('E');
            playerColCoord+=1;
            map[playerRowCoord][playerColCoord].setState('P');
            break;
          case 'S':
            cout << "Attacked Skeleton" << endl;
            p1.modifyHealth(p1.getHealth()-s1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            s1.modifyHealth(s1.getHealth()-p1.getAttack());
            if (s1.getHealth()<=0)
            {
                cout << "Skeleton Killed!" << endl;
                p1.modifyScore(p1.getScore()+5);
                map[playerRowCoord][playerColCoord].setState('E');
                playerColCoord+=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            }
            // 2 cell ranged attack
            // when defeated, turn into coin
          case 'Z':
            cout << "Attacked Zombie" << endl;
            p1.modifyHealth(p1.getHealth()-z1.getAttack());
            if (p1.getHealth()<=0){
                cout << "You died!" << endl;
                playing = false;
                break;
            }
            z1.modifyHealth(z1.getHealth()-p1.getAttack());
            if (z1.getHealth()<=0)
            {
                cout << "Zombie Killed!" << endl;
                p1.modifyScore(p1.getScore()+3);
                map[playerRowCoord][playerColCoord].setState('E');
                playerColCoord+=1;
                map[playerRowCoord][playerColCoord].setState('P');
                break;
            } else {
              cout << "Zombie health left: " << z1.getHealth() << endl;
              break;
            }
            // melee attack
            // zombie revives after 5 moves?
            // when defeated, turn into coin
          //ELIXIR IMPLEMENTATION
          case 'X':
              cout << "Drank elixir: health +1, attack +1" << endl;
              p1.modifyHealth(p1.getHealth()+e1.getHealth());
              p1.modifyAttack(p1.getAttack()+e1.getAttack());
              map[playerRowCoord][playerColCoord].setState('E');
              playerColCoord+=1;
              map[playerRowCoord][playerColCoord].setState('P');
              break;
          //APPLE IMPLEMENTATION
          case 'A':
          cout << "Ate apple: health +1" << endl;
          p1.modifyHealth(p1.getHealth()+a1.getHealth());
          p1.modifyAttack(p1.getAttack()+a1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerColCoord+=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          //KNIFE IMPLEMENTATION
          case 'K':
          cout << "Took knife: attack +1" << endl;
          p1.modifyHealth(p1.getHealth()+k1.getHealth());
          p1.modifyAttack(p1.getAttack()+k1.getAttack());
          map[playerRowCoord][playerColCoord].setState('E');
          playerColCoord+=1;
          map[playerRowCoord][playerColCoord].setState('P');
          break;
          case 'C':
            //coins++;
            p1.modifyScore(p1.getScore()+1);
            map[playerRowCoord][playerColCoord].setState('E');
            playerColCoord+=1;
            map[playerRowCoord][playerColCoord].setState('P');
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
      playerRowCoord -= 5;
    }
    for (int i = botrow+9; i >= botrow; i--){ // print shown map
      for (int j = 0; j < 10; j++){
        map[i][j].printCell();
      }
      cout << endl;
    }
    cout << "Score: " << p1.getScore() << " Health: " << p1.getHealth() << " Attack: " << p1.getAttack() << endl;
  }
}

char getch(){ // getch from conio.h in linux
	char c;
	system("stty raw");
	c = getchar();
	system("stty sane");
	return(c);
}

void clearscreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void random5rows(vector<vector<cell>> &vec, int startingrow){ // line 52 - 217: presets of 5 rows each for random world generation
  uniform_int_distribution<int> d(0,7);
  random_device rd1; //uses RDRND or /dev/urandom
  int presetnum = d(rd1); //implementing random number from 0-7
  switch(presetnum){
    //Design 1
    case 0:
      for (int i = 0; i < 4; i++){
        vec[startingrow][i].setState('W');
      }
      for (int i = 6; i < 10; i++){
        vec[startingrow][i].setState('W');
      }
      for (int i = 1; i < 3; i++){
        vec[startingrow+2][i].setState('W');
      }
      for (int i = 7; i < 9; i++){
        vec[startingrow+2][i].setState('W');
      }
      vec[startingrow+1][3].setState('Z'); //ZOMBIE
      vec[startingrow+1][6].setState('C');
      vec[startingrow+2][3].setState('C');
      vec[startingrow+2][6].setState('C');
      vec[startingrow+2][0].setState('E'); //elixir
      vec[startingrow+2][9].setState('E'); //elixir
      vec[startingrow+3][0].setState('C');
      vec[startingrow+3][1].setState('Z'); //ZOMBIE
      vec[startingrow+3][2].setState('W');
      vec[startingrow+3][7].setState('W');
      vec[startingrow+3][8].setState('C');
      vec[startingrow+3][9].setState('C');
      for (int i = 0; i < 3; i++){
        vec[startingrow+4][i].setState('W');
      }
      for (int i = 7; i < 10; i++){
        vec[startingrow+4][i].setState('W');
      }
      break;
    //Design 2
    case 1:
      for (int i = startingrow; i < startingrow+4; i++){
        for (int j = 0; j < 10; j++){
          if (i%5 == j | i%5 == j+1 | i%5 + 4 == j | i%5 + 5 == j){
            vec[i][j].setState('W');
          }
        }
      }
      vec[startingrow][9].setState('W');
      vec[startingrow][3].setState('C');
      vec[startingrow][6].setState('C');
      vec[startingrow+1][4].setState('C');
      vec[startingrow+1][7].setState('A'); //APPLE
      vec[startingrow+2][5].setState('C');
      vec[startingrow+2][8].setState('C');
      vec[startingrow+3][1].setState('X'); //elixir
      vec[startingrow+3][6].setState('X'); //elixir
      vec[startingrow+4][2].setState('C');
      vec[startingrow+4][7].setState('C');
      break;
    //Design 3
    case 2:
      for (int i = startingrow; i < startingrow+4; i++){
        for (int j = 0; j < 10; j++){
          if (i%5 == 10-j | i%5 == 9-j | i%5 == 5-j | i%5 == 4-j){
            vec[i][j].setState('W');
          }
        }
      }
      vec[startingrow][0].setState('W');
      vec[startingrow][3].setState('C');
      vec[startingrow][6].setState('C');
      vec[startingrow+1][2].setState('Z'); //ZOMBIE
      vec[startingrow+1][5].setState('C');
      vec[startingrow+2][1].setState('C');
      vec[startingrow+2][4].setState('C');
      vec[startingrow+3][3].setState('C');
      vec[startingrow+3][8].setState('X'); //elixir
      vec[startingrow+4][2].setState('C');
      vec[startingrow+4][7].setState('Z'); //ZOMBIE
      break;
    //Design 4
    case 3:
      for (int i = 0; i < 4; i++){
        vec[startingrow+1+i][0].setState('W');
      }
      vec[startingrow+1][1].setState('W');
      for (int i = 0; i < 3; i++){
        vec[startingrow+1+i][2].setState('W');
      }
      vec[startingrow+3][3].setState('W');
      for (int i = 0; i < 3; i++){
        vec[startingrow+1+i][4].setState('W');
      }
      for (int i = 0; i < 4; i++){
        vec[startingrow+1][6+i].setState('W');
        vec[startingrow+3][6+i].setState('W');
      }
      for (int i = 0; i < 3; i++){
        vec[startingrow][7+i].setState('C');
        vec[startingrow+2][7+i].setState('C');
      }
      vec[startingrow+1][3].setState('C');
      vec[startingrow+2][3].setState('Z'); //ZOMBIE
      vec[startingrow+2][1].setState('C');
      vec[startingrow+3][1].setState('A'); //APPLE
      break;
    //Design 5
    case 4:
      for (int i = 0; i < 4; i++){
        vec[startingrow+1][i].setState('W');
        vec[startingrow+3][i].setState('W');
        vec[startingrow+1+i][9].setState('W');
      }
      for (int i = 0; i < 3; i++){
        vec[startingrow][i].setState('C');
        vec[startingrow+2][i].setState('C');
        vec[startingrow+1+i][5].setState('W');
        vec[startingrow+1+i][7].setState('W');
      }
      vec[startingrow+3][6].setState('W');
      vec[startingrow+1][8].setState('W');
      vec[startingrow+1][6].setState('C');
      vec[startingrow+2][6].setState('Z'); //ZOMBIE
      vec[startingrow+2][8].setState('C');
      vec[startingrow+3][8].setState('C');
      break;
    //Design 6
    case 5:
      for (int i = 0; i < 3; i++){
        vec[startingrow+2+i][0].setState('W');
        vec[startingrow+i][9].setState('W');
        vec[startingrow+3][2+i].setState('W');
        vec[startingrow+1][5+i].setState('W');
      }
      for (int i = 0; i < 2; i++){
        vec[startingrow+2+i][1].setState('C');
        vec[startingrow+1+i][8].setState('K'); //KNIFE
        vec[startingrow+2][3+i].setState('C');
        vec[startingrow+2][5+i].setState('C');
      }
      vec[startingrow+1][1].setState('W');
      vec[startingrow+2][2].setState('W');
      vec[startingrow+2][7].setState('W');
      vec[startingrow+3][8].setState('W');
      vec[startingrow+1][2].setState('C');
      vec[startingrow+3][7].setState('C');
      break;
    //Design 7
    case 6:
      for (int i = 0; i < 3; i++){
        vec[startingrow+i][0].setState('W');
        vec[startingrow+2+i][9].setState('W');
        vec[startingrow+1][2+i].setState('W');
        vec[startingrow+3][5+i].setState('W');
      }
      for (int i = 0; i < 2; i++){
        vec[startingrow+1+i][1].setState('C');
        vec[startingrow+2+i][8].setState('C');
        vec[startingrow+2][3+i].setState('C');
        vec[startingrow+2][5+i].setState('C');
      }
      vec[startingrow+3][1].setState('W');
      vec[startingrow+2][2].setState('W');
      vec[startingrow+2][7].setState('W');
      vec[startingrow+1][8].setState('W');
      vec[startingrow+3][2].setState('C');
      vec[startingrow+1][7].setState('C');
      break;
    //Design 8
      case 7:
      for (int i = 0; i < 3; i++){
        vec[startingrow+2+i][0].setState('W');
        vec[startingrow+i][9].setState('W');
        vec[startingrow+3][2+i].setState('W');
        vec[startingrow+1][5+i].setState('W');
      }
      for (int i = 0; i < 2; i++){
        vec[startingrow+2+i][1].setState('C');
        vec[startingrow+1+i][8].setState('C');
        vec[startingrow+2][5+i].setState('C');
      }
      vec[startingrow+2][3].setState('S'); //SKELETON
      vec[startingrow+2][4].setState('C');
      vec[startingrow+1][1].setState('C');
      vec[startingrow+2][2].setState('W');
      vec[startingrow+2][7].setState('W');
      vec[startingrow+3][8].setState('K'); //KNIFE
      vec[startingrow+1][2].setState('K'); //KNIFE
      vec[startingrow+3][7].setState('C');
      vec[startingrow+1][4].setState('W');
      break;
    //Error for generating world
    default:
      cerr << "World Generation Error" << endl;
      break;
  }
}
