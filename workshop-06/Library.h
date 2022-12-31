#include <string>
#include "Book.h"

class library{
public:
	book *library = new book[10]; // stores 10 types of books
	int bookCount = 0;
	bool checkOut(book boook);
	bool addBook(book myBook);
	int getBookCount();
};
