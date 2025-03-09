#ifndef _BRIDGE_ENGINE_H_
#define _BRIDGE_ENGINE_H_

#include "compile_set.h"
#if PLATFORM == PLATFORM_WINDOWS
#ifndef BHDLL
#define BHDLL __declspec(dllexport)
#else
#define BHDLL __declspec(dllimport)
#endif
#else
#define BHDLL
#endif

// 头文件
#if PLATFORM != PLATFORM_XJ380
// OpenGL

#elif PLATFORM == PLATFORM_XJ380
// XAPI

#endif

#define DEBUG

// sw_main.cpp
BHDLL bool InitEngine(int width, int height, char* title);

#endif
