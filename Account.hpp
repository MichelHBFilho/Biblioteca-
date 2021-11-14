#pragma once
#include <string>
#include <array>
class Account {
private:
	std::string name;
	std::array<int, 32> password;
public:
	virtual bool permission() {
		return false;
	}
	Account(std::string name, std::array<int, 32> password);
	std::string getName() const;
	std::array<int, 32> getPassword() const;
};

class Manager : public Account {
public:
	bool permission() override {
		return true;
	}
	Manager(std::string, std::array<int, 32>);
};

class Client : public Account {
public:
	Client(std::string, std::array<int, 32>);
};

