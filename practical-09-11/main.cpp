#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "soldier.h"
#include "man.h"
#include "specialist.h"
#include "officer.h"
#include "general.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


//Forward call function
string **parade(vector<man> &men, specialist &paradeRSM, officer &paradeCommander, general &paradeInspector, int cols);
// void conductParade(soldier **parade, int cols);
void polyPrint(soldier * a);
void salute(soldier *soldier1, soldier *soldier2);
void rifleTraining();

//main function
int main(void){
  bool recruiting = true;

  //initialize vector for ranks
  vector<man> men;
  vector<specialist> specs;
  vector<officer> sirs;
  vector<general> upz;

  //recruiting process
  while (recruiting){
    cout << "Enlisting (1) or Stop (0): " << endl;
    cin >> recruiting;
    string name;
    int nric;
    char seniority;
    int height;
    string rank;
    
    //'1' entered
    if (recruiting == 1){
      cout << "Enter name, nric, seniority (Man (m) / Specialist (s) / Officer (o) / General (g)), rank, and height: " << endl;
      cin >> name >> nric >> seniority >> rank >> height;
      switch (seniority){
        case 'm': //Man
        case 'M':
          men.push_back(man(name,nric,rank,height));
          break;
        case 's': //Specialist
        case 'S':
          specs.push_back(specialist(name,nric,rank,height));
          break;
        case 'o': //Officer
        case 'O':
          sirs.push_back(officer(name,nric,rank,height));
          break;
        case 'g': //General
        case 'G':
          upz.push_back(general(name,nric,rank,height));
          break;
        default:
          cerr << "Input Error" << endl;
          break;
      }
    } else{ // '0' entered
      cout << "Stopped recruiting." << endl;
    }
  }
  // ACTION: Parade, Salute, Check Pay, Change Rank, Exit
  int action = 0;
  while (action != 6){
    cout << "Parade (1), Salute(2), Check Pay (3), Change Rank (4), Rifle Training (5), Exit (6), or ORD (7)?" << endl;
    cin >> action;
    switch (action){
      //Parade
      case 1:{
        //initialize
        int rsm;
        int pc;
        int pi;
        int columns = men.size()/5;
        int empty = 5 - men.size()%5;
        if (empty != 5){
          columns += 1;
        }
        //Selection of parade commanders
        cout << "Select Parade RSM (specialist 1 - " << specs.size() << "): " << endl;
        cin >> rsm;
        cout << "Select Parade Commander (officer 1 - " << sirs.size() << "): " << endl;
        cin >> pc;
        cout << "Select Parade Inspector (general 1 - " << upz.size() << "): " << endl;
        cin >> pi;
        string **paradeFormation = parade(men, specs[rsm-1], sirs[pc-1], upz[pi-1], columns);
        for (int j = 0; j < 8; j++){
          for (int i = 0; i < columns; i++){
            cout << paradeFormation[i][j];
          }
          cout << endl;
        }
        //conductParade(paradeFormation, columns);
        for (int i = 0; i < columns; i++){
          delete[] paradeFormation[i];
          // cerr << "deleted row " << i+1 << endl;
        }
        delete paradeFormation;
        break;

        //Salute
      } case 2:{
        //initialize
        char sen1;
        char sen2;
        int ic1;
        int ic2;
        int loopsize1;
        int loopsize2;
        soldier *sol1;
        soldier *sol2;
        bool found1 = false;
        bool found2 = false;
        //first soldier
        cout << "Enter first soldier's seniority (Man (m) / Specialist (s) / Officer (o) / General (g)) and NRIC: ";
        cin >> sen1 >> ic1;
        switch (sen1){
          case 'm': //Man
          case 'M':
            loopsize1 = men.size();
            for (int i = 0; i < loopsize1; i++){
              if (ic1 == men[i].getNRIC()){
                sol1 = &men[i];
                found1 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic1 << "' not found." << endl; //NOT FOUND
              }
            }
            break;
          case 's': //Specialist
          case 'S':
            loopsize1 = specs.size();
            for (int i = 0; i < loopsize1; i++){
              if (ic1 == specs[i].getNRIC()){
                sol1 = &specs[i];
                found1 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic1 << "' not found." << endl;
              }
            }
            break;
          case 'o': //Officer
          case 'O':
            loopsize1 = sirs.size();
            for (int i = 0; i < loopsize1; i++){
              if (ic1 == sirs[i].getNRIC()){
                sol1 = &sirs[i];
                found1 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic1 << "' not found." << endl;
              }
            }
            break;
          case 'g': //General
          case 'G':
            loopsize1 = upz.size();
            for (int i = 0; i < loopsize1; i++){
              if (ic1 == upz[i].getNRIC()){
                sol1 = &upz[i];
                found1 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic1 << "' not found." << endl;
              }
            }
            break;
          default:
            cerr << "Unrecognised seniority." << endl;
            break;
        }
        //second soldier
        cout << "Enter second soldier's seniority (Man (m) / Specialist (s) / Officer (o) / General (g)) and NRIC: ";
        cin >> sen2 >> ic2;
        switch (sen2){
          case 'm': //Man
          case 'M':
            loopsize2 = men.size();
            for (int i = 0; i < loopsize2; i++){
              if (ic2 == men[i].getNRIC()){
                sol2 = &men[i];
                found2 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic2 << "' not found." << endl;
              }
            }
            break;
          case 's': //Specialist
          case 'S':
            loopsize2 = specs.size();
            for (int i = 0; i < loopsize2; i++){
              if (ic2 == specs[i].getNRIC()){
                sol2 = &specs[i];
                found2 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic2 << "' not found." << endl;
              }
            }
            break;
          case 'o': //Officer
          case 'O':
            loopsize2 = sirs.size();
            for (int i = 0; i < loopsize2; i++){
              if (ic2 == sirs[i].getNRIC()){
                sol2 = &sirs[i];
                found2 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic2 << "' not found." << endl;
              }
            }
            break;
          case 'g': //General
          case 'G':
            loopsize2 = upz.size();
            for (int i = 0; i < loopsize2; i++){
              if (ic2 == upz[i].getNRIC()){
                sol2 = &upz[i];
                found2 = true;
                break;
              } else{
                cout << "Soldier with NRIC '" << ic2 << "' not found." << endl;
              }
            }
            break;
          default:
            cerr << "Unrecognised seniority." << endl;
            break;
        }
        if (found1 == true && found2 == true){
          salute(sol1, sol2);
        } else{
          cerr << "One or more soldiers not found." << endl;
        }
        break;
      } case 3:{ //Check Pay
        char sen = '\0';
        int ic = 0;
        int loopsize = 0;
        cout << "Enter seniority (Man (m) / Specialist (s) / Officer (o) / General (g)) and NRIC: " << endl;
        cin >> sen >> ic;
        switch (sen){
          case 'm': //Man
          case 'M':
            loopsize = men.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == men[i].getNRIC()){
                cout << "Checking pay of man: " << men[i].getName() << endl << "Monthly Pay: " << men[i].getPay() << endl;
                break;
              } else{
                cout << "Man with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 's': //Specialist
          case 'S':
            loopsize = specs.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == specs[i].getNRIC()){
                cout << "Checking pay of specialist: " << specs[i].getName() << endl << "Monthly Pay: " << specs[i].getPay() << endl;
                break;
              } else{
                cout << "Specialist with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 'o': //Officer
          case 'O':
            loopsize = sirs.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == sirs[i].getNRIC()){
                cout << "Checking pay of officer: " << sirs[i].getName() << endl << "Monthly Pay: " << sirs[i].getPay() << endl;
                break;
              } else{
                cout << "Officer with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 'g': //General
          case 'G':
            loopsize = upz.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == upz[i].getNRIC()){
                cout << "Checking pay of general: " << upz[i].getName() << endl << "Monthly Pay: " << upz[i].getPay() << endl;
                break;
              } else{
                cout << "General with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          default:
            cerr << "Unrecognised seniority." << endl;
            break;
        }
        break;
      } case 4:{ //Change Rank
        //initialize
        char sen;
        int ic;
        int loopsize;
        string oldRank;
        string newRank;
        cout << "Enter soldier's seniority (Man (m) / Specialist (s) / Officer (o) / General (g)) and NRIC: ";
        cin >> sen >> ic;
        switch (sen){
          case 'm': //Man
          case 'M':
            loopsize = men.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == men[i].getNRIC()){
                cout << "Enter new rank: " << endl;
                cin >> newRank;
                oldRank = men[i].getRank();
                men[i].setRank(newRank);
                cout << "Changed " << men[i].getName() << "'s rank from " << oldRank << " to " << men[i].getRank() << endl;
                break;
              } else{
                cout << "Man with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 's': //Specialist
          case 'S':
            loopsize = specs.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == specs[i].getNRIC()){
                cout << "Enter new rank: " << endl;
                cin >> newRank;
                oldRank = specs[i].getRank();
                specs[i].setRank(newRank);
                cout << "Changed " << specs[i].getName() << "'s rank from " << oldRank << " to " << specs[i].getRank() << endl;
                break;
              } else{
                cout << "Specialist with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 'o': //Officer
          case 'O':
            loopsize = sirs.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == sirs[i].getNRIC()){
                cout << "Enter new rank: " << endl;
                cin >> newRank;
                oldRank = sirs[i].getRank();
                sirs[i].setRank(newRank);
                cout << "Changed " << sirs[i].getName() << "'s rank from " << oldRank << " to " << sirs[i].getRank() << endl;
                break;
              } else{
                cout << "Officer with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 'g': //General
          case 'G':
            loopsize = upz.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == upz[i].getNRIC()){
                cout << "Enter new rank: " << endl;
                cin >> newRank;
                oldRank = upz[i].getRank();
                upz[i].setRank(newRank);
                cout << "Changed " << upz[i].getName() << "'s rank from " << oldRank << " to " << upz[i].getRank() << endl;
                break;
              } else{
                cout << "General with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          default:
            cerr << "Unrecognised seniority." << endl;
            break;
        }
        break;
      } case 5:{
        //initialize
        char sen1;
        int ic1;
        int loopsize1;
        soldier *sol1;
        bool found1 = false;
        //first soldier
        cout << "Enter first soldier's seniority (Man (m) / Specialist (s) / Officer (o) / General (g)) and NRIC: ";
        cin >> sen1 >> ic1;
        rifleTraining();
        cout << "rifle training for " << sen1 << " " << ic1 << " completed" << endl;
        break;
      } case 6:{ //Exit Program
        cout << "Exiting Program." << endl;
        break;
      default:
        cerr << "Action not found." << endl;
        break;
      }	case 7:{ //ORD
        //initialize
        char sen;
        int ic;
        int loopsize;
        cout << "Enter soldier's seniority (Man (m) / Specialist (s) / Officer (o) / General (g)) and NRIC: ";
        cin >> sen >> ic;
        switch (sen){
          case 'm': //Man
          case 'M':
            loopsize = men.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == men[i].getNRIC()){
                cout << men[i].getName() << " owadio." << endl;
                men.erase(men.begin()+i);
                break;
              } else{
                cout << "Man with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 's': //Specialist
          case 'S':
            loopsize = specs.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == specs[i].getNRIC()){
                cout << specs[i].getName() << " owadio." << endl;
                specs.erase(specs.begin()+i);
                break;
              } else{
                cout << "Specialist with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 'o': //Officer
          case 'O':
            loopsize = sirs.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == sirs[i].getNRIC()){
                cout << sirs[i].getName() << " owadio." << endl;
                sirs.erase(sirs.begin()+i);
                break;
              } else{
                cout << "Officer with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          case 'g': //General
          case 'G':
            loopsize = upz.size();
            for (int i = 0; i < loopsize; i++){
              if (ic == upz[i].getNRIC()){
                cout << upz[i].getName() << " owadio." << endl;
                upz.erase(upz.begin()+i);
                break;
              } else{
                cout << "General with NRIC '" << ic << "' not found." << endl;
              }
            }
            break;
          default:
            cerr << "Unrecognised seniority." << endl;
            break;
        }
        break;
        }
    }
  }
}

//Parade formation print out
string **parade(vector<man> &men, specialist &paradeRSM, officer &paradeCommander, general &paradeInspector, int cols){
  int emptySpaces = 5 - men.size()%5;
  int center = cols/2;
  string **output = new string *[cols];
  for (int i = 0; i < cols; i++){
    output[i] = new string[8];
  }
  for (int i = 0; i < cols-2; i++){ // col
    for (int j = 0; j < 8; j++){ // row
      if ((j == 0 | j == 1 | j == 7) && i != center){
        output[i][j] = soldier().generateNametag();
      } else if (j == 0 && i == center){
        output[i][j] = paradeInspector.generateNametag();
      } else if (j == 1 && i == center){
        output[i][j] = paradeCommander.generateNametag();
      } else if (j == 7 && i == center){
        output[i][j] = paradeRSM.generateNametag();
      } else{
        output[i][j] = men[(5*i)+(j-2)].generateNametag();
      }
    }
  }
  if (emptySpaces != 5){
    int front = 5 - emptySpaces - 1;
    for (int i = 0; i < front; i++){
      output[cols-2][2+i] = men[(cols-2)*5+i].generateNametag();
    }
    for (int i = 0; i < emptySpaces; i++){
      output[cols-2][3+i] = soldier().generateNametag();
    }
    if (emptySpaces < 4){
      output[cols-2][3+emptySpaces] = men[(cols-2)*5+front].generateNametag();
    }
    for (int i = 0; i < 5; i++){
      output[cols-1][i+2] = men[(cols*5)-emptySpaces-5+i].generateNametag();
    }
    return output;
  } else{
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 5; j++){
        output[cols-2+i][j+2] = men[(cols-2)*5+(5*i)+j].generateNametag();
      }
    }
    return output;
  }
}

/*void polyPrint(soldier *a){
  a -> printParade();
}

void conductParade(soldier **parade, int cols){
  for (int j = 0; j < 8; j++){
    for (int i = 0; i < cols; i++){
      parade[i][j]->print();
    }
    cout << endl;
  }
}*/

//implementing types of salute
void salute(soldier *soldier1, soldier *soldier2){
  if (soldier1->getRankNumber() > soldier2->getRankNumber()){
    cout << "Knock it down!! " << endl;
  } else if (soldier1->getRankNumber() < soldier2->getRankNumber()){
    cout << "Good Morning Sir! " << endl;
  } else{
    cout << "Sup bro " << endl;
  }
}
//implementing clearscreen function
void clearscreen()
{
#if defined _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//implementing rifle training stimulation
void rifleTraining()
{
  for (int i=0;i<4;i++){
    switch(i){
      case 0:
        clearscreen();
        //cout << string(50,'\n');
        cout << "|                                       |" << endl;
        cout << "|                                       |" << endl;
        cout << "|                                       |" << endl;
        cout << "|    0                       _______    |" << endl;
        cout << "|   /|\\ ︻╦╤─                |TARGET|  |" << endl;
        cout << "|    /\\                      |      |  |" << endl;
        sleep(1);
        clearscreen();
        break;
      case 1:
        cout << "|                                      |" << endl;
        cout << "|              phew                    |" << endl;
        cout << "|                                      |" << endl;
        cout << "|    0              phew      _______  |" << endl;
        cout << "|   /|\\ ︻╦╤─  -   -    -   -|TARGET| |" << endl;
        cout << "|    /\\       phew           |      | |" << endl;
        sleep(1);
        clearscreen();
        break;
      case 2:
        cout << "|                                       |" << endl;
        cout << "|            TARGET SHOT                |" << endl;
        cout << "|         training completed            |" << endl;
        cout << "|    0                        _______   |" << endl;
        cout << "|   /|\\ ︻╦╤─                |  💀  |  |" << endl;
        cout << "|    /\\                      |      |  |" << endl;
        sleep(1);
        clearscreen();
        break;
    }
  }
}
