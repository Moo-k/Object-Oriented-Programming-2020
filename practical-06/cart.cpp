#include <iostream>
using namespace std;
#include <string>
#include "meerkat.h"
#include "cart.h"

cart::cart(){
}

bool cart::addMeerkat(meerkat cat){
	if (cartCount < 4){
		*(mkcart + cartCount) = cat;
		cartCount++;
		return true;
	}	else{
		return false;
	}
}

void cart::emptyCart(){
	cartCount = 0;
}

void cart::printMeerkats(){
	for (int i = 0; i < cartCount; i++){
		cout << mkcart[i].meerkat::getName() << " " << mkcart[i].meerkat::getAge() << endl;
	}
}

cart::~cart(){
	// cout << "deleted cart" << endl;
}
