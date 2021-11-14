#include "Account.hpp"

Account::Account(std::string name, std::array<int, 32> password) :
	password(password),
	name(name)
{
}

std::string Account::getName() const {
	return name;
}

std::array<int, 32> Account::getPassword() const {
	return password;
}

Manager::Manager(std::string name, std::array<int, 32> password) :
	Account(name, password) {}

Client::Client(std::string name, std::array<int, 32> password) :
	Account(name, password) {}