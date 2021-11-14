#pragma once
#include <string>
class Book {
public:
	std::string bookName;
	std::string publishDate; // DD/MM/YYYY
	std::string author;

	Book(std::string bookName,
		std::string publishDate, std::string author) :
		bookName(bookName),
		publishDate(publishDate),
		author(author) {}
};

