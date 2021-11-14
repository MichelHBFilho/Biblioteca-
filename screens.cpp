#include <iostream>
#include "main.hpp"
#include "registerBook.hpp"
#include "log_in__sign_in.hpp"
#include "seeStock.hpp"
#include "buy.hpp"
#include "screens.hpp"

void initialScreen() {
	while (true) {
		clear();
		std::cout << "Bem vindo" << std::endl;
		std::cout << "1- Logar" << std::endl;
		std::cout << "2- Registrar" << std::endl;
		std::cout << "3- Ver estoque" << std::endl;
		std::cout << "4- Sair" << std::endl;

		int op;
		std::cin >> op;

		switch (op) {
		case 1:
			login();
			break;
		case 2:
			sign_in();
			break;
		case 3:
			seeStock();
			break;
		default:
			exit(0);
			break;
		}
	}
}

void managerScreen(Account& account) {
	while (true) {
		clear();
		std::cout << "Bom dia, " << account.getName() << std::endl;
		std::cout << "1- Adicionar livro" << std::endl;
		std::cout << "2- Ver estoque" << std::endl;
		std::cout << "3- Sair" << std::endl;

		int op;
		std::cin >> op;

		switch (op) {
		case 1:
			registerBook();
			break;
		case 2:
			seeStock();
			break;
		default:
			exit(0);
			break;
		}
	}
}

void clientScreen(Account& account) {
	while (true) {
		clear();
		std::cout << "Bom dia, " << account.getName() << std::endl;
		std::cout << "1- Comprar um livro" << std::endl;
		std::cout << "2- Ver estoque" << std::endl;
		std::cout << "3- Sair" << std::endl;

		int op;
		std::cin >> op;

		switch (op) {
		case 1:
			buyScreen();
			break;
		case 2:
			seeStock();
			break;
		default:
			exit(0);
			break;
		}
	}
}

void buyScreen() {
	std::cout << "Qual livro você deseja comprar?: ";
	std::string bookName;
	std::cin >> bookName;
	buy(bookName);
}