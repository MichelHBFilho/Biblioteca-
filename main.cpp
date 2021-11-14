#include <iostream>
#include "files.hpp"
#include "Account.hpp"
#include "cryptography.hpp"
#include "main.hpp"
using namespace std;

#ifdef WIN32 or _WIN32
#define WINDOWS
void clear() {
	system("cls");
}
#else
void clear() {
	system("clear");
}
#endif

void loginPassword(Account& account) {
	cout << "Insira sua senha: ";
	std::string password;
	cin >> password;
	if (password != decrypts(account.getPassword())) {
		cout << "Senha incorreta" << endl;
		cout << "Tentar novamente? [S/n]" << endl;
		char op;
		cin >> op;
		switch (op) {
		case 's' || 'S':
			loginPassword(account);
			break;
		default:
			exit(0);
		}
	}

	cout << "Entrou com sucesso" << endl;
	if (account.permission()) {
		managerScreen(account);
	}
	else {
		clientScreen(account);
	}
}

void login() {
	clear();
	cout << "Insira seu nome: ";
	string name;
	cin >> name;
	vector<Account> accounts = readAccountFile();
	for (Account account : accounts) {
		if (account.getName() == name) {
			loginPassword(account);
			return;
		}
	}
	cout << "Não encontramos sua conta" << endl;
	cout << "1- Tentar novamente" << endl;
	cout << "2- Registrar" << endl;
	cout << "3- Sair" << endl;
	short int op;
	cin >> op;
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
	cout << "Seu nome: ";
	std::string name;
	cin >> name;
	cout << "Sua senha: ";
	std::string password;
	cin >> password;
	vector<Account> accounts = readAccountFile();
	accounts.push_back(Client(name, encrypt(password)));
	saveAccountFile(accounts);
	initialScreen();
}

void initialScreen() {
	cout << "Bem vindo" << endl;
	cout << "1- Logar" << endl;
	cout << "2- Registrar" << endl;
	cout << "3- Ver estoque" << endl;
	cout << "4- Sair" << endl;

	int op;
	cin >> op;

	switch (op) {
	case 1:
		login();
		break;
	case 2:
		sign_in();
		break;
	case 3:
		break;
	default:
		exit(0);
		break;
	}
}

void managerScreen(Account& account) {
	while (true) {
		clear();
		cout << "Bom dia, " << account.getName() << std::endl;
		cout << "1- Adicionar livro" << endl;
		cout << "2- Ver estoque" << endl;
		cout << "3- Listar ultimas vendas" << endl;
		cout << "4- Sair" << endl;

		int op;
		cin >> op;

		switch (op) {
		case 1:
			/*registerBook();*/
			break;
		case 2:
			break;
		case 3:
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
		cout << "Bom dia, " << account.getName() << endl;
		cout << "1- Comprar um livro" << endl;
		cout << "2- Ver estoque" << endl;
		cout << "3- Sair" << endl;

		int op;
		cin >> op;

		switch (op) {
		case 1:
			break;
		case 2:
			break;
		default:
			exit(0);
			break;
		}
	}	
}

//void registerBook() {
//	clear();
//	cout << "Nome do livro: ";
//	string name;
//	cin >> name;
//
//	cout << "Autor: ";
//	string author;
//	cin >> author;
//
//	cout << "Data de lançamento: ";
//	string date;
//	cin >> date;
//
//	cout << "Quantos livros tem em estoque?: ";
//	int quantity;
//	cin >> quantity;
//
//	auto books = readBooksFile();
//	
//	Book book(name, date, author);
//	books.first.push_back(book);
//	books.second[book] = quantity;
//
//	saveBooksFile(books.first, books.second);
//
//	cout << "Adicionar mais um livro? [S/n]: " << endl;
//	char op;
//	cin >> op;
//
//	if (op == 'S' || op == 's') {
//		registerBook();
//	}
//}

int main() {
#ifdef WINDOWS 
	system("chcp 65001");
#endif
	clear();
	initialScreen();
	return 0;
}