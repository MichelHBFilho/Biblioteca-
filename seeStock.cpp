#include <iostream>
#include <vector>
#include "Book.hpp"
#include "files.hpp"
void seeStock() {
	std::vector<Book> books = readBookFile();
	for (Book book : books) {
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Livro: " << book.bookName << std::endl;
		std::cout << "Autor: " << book.author << std::endl;
		std::cout << "Data de lançamento: " << book.publishDate << std::endl;
		std::cout << "Quantidade em estoque: " << book.quantity << std::endl;
	}
	unsigned char op;
	std::cout << "Continuar? [S]: ";
	std::cin >> op;
}