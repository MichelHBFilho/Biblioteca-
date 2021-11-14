#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include "Book.hpp"
#include "Account.hpp"
#include "files.hpp"

std::vector<Account> readAccountFile() {
	std::ifstream file;
	file.open("Accounts.txt");

	if (!file.is_open()) { // Early Return
		std::cout << "O Banco não pode ser aberto" << std::endl;
		exit(404);
	}

	int numAccounts;
	file >> numAccounts;
	std::vector<Account> accounts;

	for (int i = 0; i < numAccounts; i++) {
		std::string name;
		std::array<int, 32> password;
		std::string type;

		file >> name;
		for (int i = 0; i < 32; i++) {
			int part;
			file >> part;
			password[i] = part;
		}
		file >> type;

		if (type == "Manager") {
			accounts.push_back(Manager(name, password));
		}
		else {
			accounts.push_back(Client(name, password));
		}
	}

	file.close();

	return accounts;
}

void saveAccountFile(std::vector<Account> accounts) {
	std::ofstream file;
	file.open("Accounts.txt");

	if (!file.is_open()) {
		std::cout << "Não foi possivel abrir o arquivo" << std::endl;
		exit(404);
	}

	file << accounts.size() << std::endl;

	for (Account account : accounts) {
		file << account.getName() << std::endl;
		for (int i : account.getPassword()) {
			file << i << " ";
		}
		file << std::endl;
		file << ((account.permission()) ? "Manager" : "Client") << std::endl;
	}
}

//void saveBooksFile(std::vector<Book> books, std::map<Book, int> mapQuantity) {
//	std::ofstream file;
//	file.open("Books.txt");
//
//	if (!file.is_open()) {
//		std::cout << "Não foi possivel abrir o banco" << std::endl;
//		exit(404);
//	}
//
//	file << books.size() << std::endl;
//
//	for (Book book : books) {
//		file << book.bookName << std::endl;
//		file << book.author << std::endl;
//		file << book.publishDate << std::endl;
//		file << mapQuantity[book] << std::endl;
//	}
//}

//std::pair<std::vector<Book>, std::map<Book, int>> readBooksFile() {
//	std::ifstream file;
//	file.open("Books.txt");
//
//	if (!file.is_open()) {
//		std::cout << "Não foi possivel abrir o banco" << std::endl;
//		exit(404);
//	}
//
//	int numBooks;
//	file >> numBooks;
//
//	std::vector<Book> books;
//	std::map<Book, int> mapQuantity;
//
//	for (int i = 0; i < numBooks; i++) {
//		std::string bookName;
//		std::string author;
//		std::string publishDate;
//		int quantity;
//
//		file >> bookName;
//		file >> author;
//		file >> publishDate;
//		file >> quantity;
//
//		Book book(bookName, author, publishDate);
//
//		books.push_back(book);
//		mapQuantity[book] = quantity;
//	}
//
//	std::pair<std::vector<Book>, std::map<Book, int>> map =
//		std::make_pair(books, mapQuantity);
//
//	return map;
//}