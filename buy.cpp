#include "Book.hpp"
#include "files.hpp"
#include <string>
#include <vector>
#include <iostream>
void buy(std::string bookName) {
	std::vector<Book> books = readBookFile();
	for (unsigned int i = 0; i < books.size(); i++) {
		if (books[i].bookName == bookName) {
			books[i].quantity--;
			std::cout << "Compra realizada com sucesso" << std::endl;
			saveBookFile(books);
			return;
		}
	}
	std::cout << "Não achamos nenhum livro com esse nome, em nosso estoque" << std::endl;
}