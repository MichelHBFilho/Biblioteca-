#include <string>
#include <cstdlib>
#include <array>
#include <ctime>
#include "cryptography.hpp"

std::array<int, 32> encrypt(std::string password) {
	std::array<int, 32> passwordInAscii = toAscii(password);
	saveKey(passwordInAscii);
	for (unsigned int i = 0; i < 31; i++) {
		passwordInAscii[i] = passwordInAscii[i] * passwordInAscii[31];
	}
	return passwordInAscii;
}

std::array<int, 32> toAscii(std::string& senha) {
	std::array<int, 32> passwordInAscii;
	for (unsigned int i = 0; i < 32; i++) {
		passwordInAscii[i] = 0;
	}
	for (unsigned int i = 0; i < senha.size(); i++) {
		passwordInAscii[i] = (int)senha[i];
	}
	return passwordInAscii;
}

int makeKey() {
	int key = (rand() * time(NULL) / 11) % 300;
	return key;
}

void saveKey(std::array<int, 32>& password) {
	password[31] = makeKey();
}

std::string decrypts(std::array<int, 32> password) {
	char passwordDecrypted[32] = "";
	for (unsigned int i = 0; i < 31; i++) {
		if (password[31] == 0) return "";
		passwordDecrypted[i] = char(password[i] / password[31]);
	}
	return std::string(passwordDecrypted);
}