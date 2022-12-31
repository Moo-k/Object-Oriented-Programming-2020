#include <iostream>
using namespace std;

void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents){
  cout << "Report Card ";
  for (int i = 0; i < 4; i++){
    cout << courses[i];
    if (i < 3){
      cout << " ";
    }
  }
  cout << endl;
  for ( int j = 0 ; j < nstudents; j++){
    cout << students[j] << " ";
    for (int k = 0; k < 4; k++){
      cout << report_card[j][k];
      if (k < (nstudents)){
      cout << " ";
    }
    }
    cout << endl;
  }
}
