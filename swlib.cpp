#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
#include <iostream>
#endif

void printcon(const char* str) {
#if PLATFORM == PLATFORM_WINDOWS
	// Windows
	std::cout << str << std::endl;
#elif PLATFORM == PLATFORM_XJ380
	// XJ380
#endif
	return;
}

void inputcon(char* str) {
#if PLATFORM == PLATFORM_WINDOWS
	// Windows
	std::cin >> str;
#elif PLATFORM == PLATFORM_XJ380
	// XJ380
#endif
	return;
}
