#include <string>
#include <cstdlib>
#include <array>
#include <ctime>
#include "cryptography.hpp"

std::array<int, 32> encrypt(std::string password) {
	std::array<int, 32> passwordInAscii = toAscii(password);
	saveKey(passwordInAscii);
	for (int i = 0; i < 31; i++) {
		passwordInAscii[i] = passwordInAscii[i] * passwordInAscii[31];
	}
	return passwordInAscii;
}

std::array<int, 32> toAscii(std::string& senha) {
	std::array<int, 32> passwordInAscii;
	for (int i = 0; i < 32; i++) {
		passwordInAscii[i] = 0;
	}
	for (int i = 0; i < senha.size(); i++) {
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