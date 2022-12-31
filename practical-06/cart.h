#ifndef _CART_H
#define _CART_H
#include <iostream>
using namespace std;
#include <string>
#include "meerkat.h"

class cart{
public:
	cart();
	int cartCount = 0;
	meerkat *mkcart = new meerkat[4];
	bool addMeerkat(meerkat cat);
	void emptyCart();
	void printMeerkats();
	~cart();
};

#endif
