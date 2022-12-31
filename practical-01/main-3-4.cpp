#include <iostream>

extern void passorfail(char grade);

int main(){
  char grade;

  std::cout << "Enter grade: " << std::endl;
  std::cin >> grade;

  passorfail(grade);
  return 0;
}
