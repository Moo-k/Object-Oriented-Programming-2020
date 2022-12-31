#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

book::book(){
	title = "?";
	genre = "?";
	numberof = 0;
}

book::book(std::string myTitle, std::string myGenre, int myNumberof){
	title = myTitle;
	genre = myGenre;
	numberof = myNumberof;
};

void book::setTitle(std::string myTitle){
	title = myTitle;
};

std::string book::getTitle(){
	return title;
};

void book::setGenre(std::string myGenre){
	genre = myGenre;
};

std::string book::getGenre(){
	return genre;
};

void book::setNumberof(int myNumberof){
	numberof = myNumberof;
};

int book::getNumberof(){
	return numberof;
};

book::~book(){
}
