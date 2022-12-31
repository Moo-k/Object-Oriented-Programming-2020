#include <string>
using namespace std;
#include "zoo.h"
#include "animal.h"
#include "hunter.h"
#include "vegie.h"
#include "sort_by_animalID.h"

void sort_by_animalID::sort(animal **animals,int n){
  int swap = 1;
    animal* temp;
    for(int i = n - 1; i > 0 && swap; i--){
        swap = 0;
        for (int j = 0; j < i; j++){
            if (animals[j]->get_animalID() > animals[j+1]->get_animalID()){ 
                temp = animals[j];
                animals[j] = animals[j+1];
                animals[j+1] = temp;
                swap = 1;
            }
        }
    }
}
