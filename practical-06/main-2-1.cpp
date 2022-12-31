#include <iostream>
using namespace std;
#include <string>
#include "meerkat.h"
#include "cart.h"

int main(){
	meerkat mk1; mk1.setName("mk1"); mk1.setAge(12);
	meerkat mk2; mk2.setName("mk2"); mk2.setAge(24);
	meerkat mk3; mk3.setName("mk3"); mk3.setAge(36);
	meerkat mk4; mk4.setName("mk4"); mk4.setAge(48);
	meerkat mk5; mk5.setName("mk5"); mk5.setAge(60);
	
	cart ct1;
	if (ct1.cart::addMeerkat(mk1) == true){cout<<"mk1 successfully added"<<endl;} else{cout<<"failed to add mk1"<<endl;}
	if (ct1.cart::addMeerkat(mk2) == true){cout<<"mk2 successfully added"<<endl;} else{cout<<"failed to add mk2"<<endl;}
	if (ct1.cart::addMeerkat(mk3) == true){cout<<"mk3 successfully added"<<endl;} else{cout<<"failed to add mk3"<<endl;}
	if (ct1.cart::addMeerkat(mk4) == true){cout<<"mk4 successfully added"<<endl;} else{cout<<"failed to add mk4"<<endl;}
	if (ct1.cart::addMeerkat(mk5) == true){cout<<"mk5 successfully added"<<endl;} else{cout<<"failed to add mk5"<<endl;}
	
	ct1.cart::printMeerkats();
	
	ct1.cart::emptyCart();
	
	ct1.cart::printMeerkats();
	
	return 0;
}
