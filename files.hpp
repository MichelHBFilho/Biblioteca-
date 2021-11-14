#include <fstream>
#include <vector>
#include <iostream>
#include <map>
#include "Book.hpp"
#include "Account.hpp"

std::vector<Account> readAccountFile();
void saveAccountFile(std::vector<Account> accounts);
std::vector<Book> readBookFile();
void saveBookFile(std::vector<Book> books);