#include <string>
#include <cstdlib>
#include <array>
#include <ctime>

std::array<int, 32> encrypt(std::string password);
std::array<int, 32> toAscii(std::string& senha);
int makeKey();
void saveKey(std::array<int, 32>& password);
std::string decrypts(std::array<int, 32> password);