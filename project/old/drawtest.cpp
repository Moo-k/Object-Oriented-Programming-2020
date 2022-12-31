#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <chrono>
#include <random>

int main(void){
  vector<int*> deck;
  int array[2] = {1,11};
	int *ace = &array[0];
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

  //unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

  uniform_int_distribution<int> d(0, deck.size());
  random_device rd1;
  int randomindex = d(rd1);
  cout << "random index: " << randomindex << endl;
	int *carddrawn = deck[randomindex];
  for (int *n : deck){
    cout << *(n) << " ";
  }
  cout << endl;
	deck.erase(deck.begin() + randomindex);
  for (int *n : deck){
    cout << *(n) << " ";
  }
  cout << endl;
  cout << "deck size: " << deck.size() << endl;;
  cout << "card drawn: " << *(carddrawn) << endl;
}
