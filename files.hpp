#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include "Book.hpp"
#include "Account.hpp"

std::vector<Account> readAccountFile();
void saveAccountFile(std::vector<Account> accounts);
//std::pair<std::vector<Book>, std::map<Book, int>> readBooksFile();
//void saveBooksFile(std::vector<Book> books, std::map<Book, int> mapQuantity);