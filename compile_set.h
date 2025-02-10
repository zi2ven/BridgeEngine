#pragma once

#define PLATFORM_XJ380 0
#define PLATFORM_WINDOWS 1
#define PLATFORM_LINUX 2

#ifdef _WIN32
#define PLATFORM PLATFORM_WINDOWS
#elif defined(linux)
#define PLATFORM PLATFORM_LINUX
#endif
