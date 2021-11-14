#pragma once
#include "Account.hpp"

#ifdef WIN32 or _WIN32
#define WINDOWS
inline void clear() {
	system("cls");
}
#else
inline void clear() {
	system("clear");
}
#endif