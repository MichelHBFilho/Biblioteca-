#pragma once
#include <string>
class Book {
public:
	std::string bookName;
	std::string publishDate; // DD/MM/YYYY
	std::string author;
	int quantity;

	Book(std::string bookName,
		std::string publishDate, std::string author, int quantity) :
		bookName(bookName),
		publishDate(publishDate),
		author(author),
		quantity(quantity) {}
};

