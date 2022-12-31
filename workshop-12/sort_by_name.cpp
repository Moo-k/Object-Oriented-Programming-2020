#include <string>
using namespace std;
#include "animal.h"
#include "sort_by_name.h"

void sort_by_name::sort(animal **animals,int n){
  int swap = 1;
    animal* temp;
    for(int i = n - 1; i > 0 && swap; i--){
        swap = 0;
        for (int j = 0; j < i; j++){
        	
            if (animals[j]->get_name() > animals[j+1]->get_name()){ 
                temp = animals[j];
                animals[j] = animals[j+1];
                animals[j+1] = temp;
                swap = 1;
            }
        }
    }
}
