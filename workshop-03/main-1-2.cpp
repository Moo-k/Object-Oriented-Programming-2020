#include <iostream>
using namespace std;
#include <string>

extern void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents);

int main(){
  string courses[4] = {"EN","SC","MT","HI"};
  int nstudents = 4;
  string students[4] = {"ALI","BOB","CAL","DAN"};
  int report_card[4][4] = {
    {75,65,63,55},
    {87,56,86,76},
    {98,78,76,57},
    {87,65,76,87}};

  print_class(courses,students,report_card,nstudents);

  return 0;
}
