#include <iostream>
#include "main.hpp"
#include "files.hpp"
#include "Book.hpp"

void registerBook() {
	clear();
	std::cout << "Nome do livro: ";
	std::string name;
	std::cin >> name;

	std::cout << "Autor: ";
	std::string author;
	std::cin >> author;

	std::cout << "Data de lançamento: ";
	std::string date;
	std::cin >> date;

	std::cout << "Quantos livros tem em estoque?: ";
	int quantity;
	std::cin >> quantity;

	std::vector<Book> books = readBookFile();
	books.push_back(Book(name, date, author, quantity));
	saveBookFile(books);
}