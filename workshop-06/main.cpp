#include <iostream>
using namespace std;
#include <string>
#include "Book.h"
#include "Library.h"

int main(){
	book book1("The Bible","Comedy",2);
	
	cout << "Book title: " << book1.getTitle() << ", Genre: " << book1.getGenre() << ", Available number: " << book1.getNumberof() << endl;
	
	book1.setGenre("Drama");
	book1.setNumberof(4);
	
	cout << "Book title: " << book1.getTitle() << ", Genre: " << book1.getGenre() << ", Available number: " << book1.getNumberof() << endl;
	
	library lib1;
	book book2("book2","Comedy",3);
	book book3("book3","Sadness",1);
	
	if (lib1.library::addBook(book1) == true){cout<<"book1 successfully added"<<endl;} else{cout<<"failed to add book1";}
	if (lib1.library::addBook(book2) == true){cout<<"book2 successfully added"<<endl;} else{cout<<"failed to add book2";}
	if (lib1.library::addBook(book3) == true){cout<<"book3 successfully added"<<endl;} else{cout<<"failed to add book3";}
	
	cout << "Total number of different titles: " << lib1.getBookCount() << endl;
	
	lib1.checkOut(book3);
	lib1.checkOut(book2);
	
	return 0;
}
