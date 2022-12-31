#include <iostream>
using namespace std;
#include <string>
#include <vector>

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

  cout << "debug whole deck: " << endl;
  for (int *n : deck){
    cout << *(n) << " ";
    if (*(n) == 1){
      cout << *(n + 1) << " ";
    }
  }
}
