#ifndef _LIBRARY_H
#define _LIBRARY_H
#include <iostream>
using namespace std;
#include <string>
#include "Book.h"
#include "Library.h"

bool library::addBook(book myBook){
	if (bookCount >= 10){
		return false;
	}	else{
		*(library + bookCount) = myBook;
		bookCount++;
		return true;
	}
};

int library::getBookCount(){
	return bookCount;
};

bool library::checkOut(book boook){
	if (bookCount == 0){
		return false;
	}	else if (boook.book::getNumberof() == 1){
		cout << "You have checked out the last copy of " << boook.book::getTitle() << "." << endl;
		boook.book::setNumberof(0);
		return true;
	}	else {
		boook.book::setNumberof(boook.book::getNumberof()-1);
		cout << "You have checked out " << boook.getTitle() << ", " << boook.getNumberof() << " copies remaining." << endl;
		return true;
	}
};

#endif
