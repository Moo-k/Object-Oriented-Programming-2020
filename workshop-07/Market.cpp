#include <string>
using namespace std;
#include "Market.h"

Market::Market(){};

void Market::setName(string marName){
	name = marName;
}

string Market::getName(){
	return name;
}

void Market::setAge(int merAge){
	age = merAge;
}

int Market::getAge(){
	return age;
}
