#include <iostream>
#include "main.hpp"
#include "files.hpp"
#include "cryptography.hpp"
#include "screens.hpp"
#include "log_in__sign_in.hpp"

void loginPassword(Account& account) {
	std::cout << "Insira sua senha: ";
	std::string password;
	std::cin >> password;
	if (password != decrypts(account.getPassword())) {
		std::cout << "Senha incorreta" << std::endl;
		std::cout << "Tentar novamente? [S/n]" << std::endl;
		char op;
		std::cin >> op;
		switch (op) {
		case 's' || 'S':
			loginPassword(account);
			break;
		default:
			exit(0);
		}
	}

	std::cout << "Entrou com sucesso" << std::endl;
	if (account.getPermission()) {
		managerScreen(account);
	}
	else {
		clientScreen(account);
	}
}

void login() {
	clear();
	std::cout << "Insira seu nome: ";
	std::string name;
	std::cin >> name;
	std::vector<Account> accounts = readAccountFile();
	for (Account account : accounts) {
		if (account.getName() == name) {
			loginPassword(account);
			return;
		}
	}
	std::cout << "Não encontramos sua conta" << std::endl;
	std::cout << "1- Tentar novamente" << std::endl;
	std::cout << "2- Registrar" << std::endl;
	std::cout << "3- Sair" << std::endl;
	short int op;
	std::cin >> op;
	switch (op) {
	case 1:
		login();
		break;
	case 2:
		sign_in();
	case 3:
		exit(0);
	}
}

void sign_in() {
	clear();
	std::cout << "Seu nome: ";
	std::string name;
	std::cin >> name;
	std::cout << "Sua senha: ";
	std::string password;
	std::cin >> password;
	std::vector<Account> accounts = readAccountFile();
	accounts.push_back(Client(name, encrypt(password)));
	saveAccountFile(accounts);
	initialScreen();
}