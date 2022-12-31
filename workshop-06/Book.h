#ifndef _BOOK_H // if book hasnt been defined, define it (so if included twice it only runs once)
#define _BOOK_H
#include <string>

class book{
public:
	std::string title;
	std::string genre;
	int numberof;
	book();
	book(std::string title, std::string genre, int numberof);
	void setTitle(std::string myTitle);
	std::string getTitle();
	void setGenre(std::string myGenre);
	std::string getGenre();
	void setNumberof(int myNumberof);
	int getNumberof();
	~book();
};

#endif
