#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include "player.h"
#include "blackjack.h"

int blackjack::array[2] = {1,11};
int *blackjack::ace = &array[0];

blackjack::blackjack(){
	for (int i = 0; i < 4; i++){
		deck.push_back(ace);
		deck.push_back(new int (2));
		deck.push_back(new int (3));
		deck.push_back(new int (4));
		deck.push_back(new int (5));
		deck.push_back(new int (6));
		deck.push_back(new int (7));
		deck.push_back(new int (8));
		deck.push_back(new int (9));
		deck.push_back(new int (10));
		deck.push_back(new int (10));
		deck.push_back(new int (10));
		deck.push_back(new int (10));
	}
	gaming = true;
}

int *blackjack::drawcard(){
	uniform_int_distribution<int> d(0, deck.size()-1);
  random_device rd1;
  int randomindex = d(rd1);
  bool newindex = true;
  for (int i = 0; i < indexesdrawn.size(); i++){
    if (randomindex == indexesdrawn[i]){
      newindex = false;
      break;
    }
  }
  while (newindex == false){
    randomindex = d(rd1);
    for (int i = 0; i < indexesdrawn.size(); i++){
    if (randomindex == indexesdrawn[i]){
      newindex = false;
    }
  }
  }
  cout << "debug whole deck: " << endl;
  for (int *n : deck){
    cout << *(n) << " ";
    if (*(n) == 1){
      cout << *(n + 1) << " ";
    }
  }
  cout << endl;
  cout << "debug random index: " << randomindex << endl;
  indexesdrawn.push_back(randomindex);
	return deck[randomindex];
}

int blackjack::maxunder21(vector<int*> hand){
  vector<int> handsums;
  handsums.push_back(0);
  vector<int> tempsum;
  for(int i = 0; i < hand.size(); i++){
    if (*(hand[i]) == 1){
      for (int j = 0; j < handsums.size(); j++){
        tempsum.push_back(handsums[j] + 1);
        tempsum.push_back(handsums[j] + 11);
      }
      for (int k = 0; k < tempsum.size(); k++){
        if (tempsum[k] > 21){
          tempsum[k] = 0;
        }
      }
      handsums = tempsum;
      tempsum.clear();
    } else{
      for (int j = 0 ; j < handsums.size(); j++){
        handsums[j] += *(hand[i]);
      }
      for (int k = 0 ; k < handsums.size(); k++){
        if (handsums[k] > 21){
          handsums[k] = 0;
        }
      }
    }
  }
  int tempmax = handsums[0];
  for (int i = 1; i < handsums.size(); i++){
    if (handsums[i] > tempmax){
      tempmax = handsums[i];
    }
  }
  return tempmax;
}

double blackjack::round(){ // 0 = bust; 1 = loss; 2 = tie; 3 = win; 4 = blackjack win; 5 = something went wrong
	dealertotal = 0;
	playertotal = 0;
	int *temp;
	bool playing = true;
  for (int i = 0; i < 2; i++){
    temp = drawcard();
		playerhand.push_back(temp);
    cout << "Card drawn: " << *(temp) << endl;
    temp = drawcard();
    dealerhand.push_back(temp);
  }
	playertotal = maxunder21(playerhand);
  dealertotal = maxunder21(dealerhand);
  cout << "Your current total is: " << playertotal << endl;
  if (playertotal == 21 && dealertotal == 21){
    cout << "TIE!" << endl;
    return 1;
  } else if(playertotal == 21 && dealertotal < 21){
    cout << "BLACKJACK!" << endl;
    return 2.5;
  } else if(dealertotal == 21 && playertotal < 21){
    cout << "DEALER BLACKJACK!" << endl;
    return 0;
  }
	bool playerturn = true;
  bool dealerturn = true;
  int hs;
  while (playerturn == true | dealerturn == true){
    cout << "Hit(1) or Stand(2)?" << endl;
    cin >> hs;
    while (hs < 1 | hs > 2){
			cout << "Invalid input" << endl << "Hit(1) or Stand(2)?" << endl;
			cin >> hs;
		}
    if (hs == 1){
      temp = drawcard();
		  playerhand.push_back(temp);
      cout << "Card drawn: " << *(temp) << endl; 
      playertotal = maxunder21(playerhand);
      cout << "Your current total is: " << playertotal << endl;
      if (playertotal == 0){
        cout << "BUST!" << endl;
        return 0;
      } else{
        break;
      }
    } else if(hs == 2){
      playerturn = false;
    }
    while (dealertotal < 17 && dealertotal > 0){
      dealerhand.push_back(drawcard());
      dealertotal = maxunder21(dealerhand);
      if (dealertotal == 0){
        cout << "Dealer Bust!" << endl;
        return 2;
      } else if(dealertotal > 16){
        dealerturn = false;
      }
    }
  }
  if (playertotal > dealertotal){
    cout << "Dealer Total: " << dealertotal << endl;
    cout << "YOU WIN!" << endl;
    return 2;
  } else if (playertotal == dealertotal){
    cout << "Dealer Total: " << dealertotal << endl;
    cout << "TIE!" << endl;
    return 1;
  } else if (playertotal < dealertotal){
    cout << "Dealer Total: " << dealertotal << endl;
    cout << "YOU LOST!" << endl;
    return 0;
  }
	return 5;
}

bool blackjack::getgaming(){
	return gaming;
}

void blackjack::setgaming(int yn){
	if(yn == 2){
		gaming = false;
	} else if (yn == 1){
    gaming = true;
  }
}

void blackjack::resetgamestate(){
	deck.clear();
	playerhand.clear();
	dealerhand.clear();
  indexesdrawn.clear();
	for (int i = 0; i < 4; i++){
		deck.push_back(ace);
		deck.push_back(new int (2));
		deck.push_back(new int (3));
		deck.push_back(new int (4));
		deck.push_back(new int (5));
		deck.push_back(new int (6));
		deck.push_back(new int (7));
		deck.push_back(new int (8));
		deck.push_back(new int (9));
		deck.push_back(new int (10));
		deck.push_back(new int (10));
		deck.push_back(new int (10));
		deck.push_back(new int (10));
	}
}

blackjack::~blackjack(){
}
