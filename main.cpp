#include <iostream>
#include "files.hpp"
#include "Account.hpp"
#include "cryptography.hpp"
#include "screens.hpp"
#include "main.hpp"

int main() {
#ifdef WINDOWS 
	system("chcp 65001");
#endif
	initialScreen();
	return 0;
}