#pragma once

#ifndef _EDLL_H_
#define _EDLL_H_

#include "compile_set.h"

#ifdef BHDLL__
#define BHDLL __declspec(dllexport)
#else
#define BHDLL __declspec(dllimport)
#endif

// paint
BHDLL void	printcon(const char* str);
BHDLL void	inputcon(char* str);

#define DEBUG

struct MOUSE_INFO {
	short x, y;
	bool lb, mb, rb;
};



#if PLATFORM == PLATFORM_WINDOWS

#include <Windows.h>  
#include <wincodec.h>
#include <commdlg.h>
#include <iostream>
#include <sstream>
#include <windowsx.h>
#include <atlconv.h>

extern HWND XBE_hWnd;
extern WNDCLASSEX Window;
extern HINSTANCE XBE_hInstance;

struct WIN_KEY_FIFO {
	unsigned short fifo[32];
	short p_read, p_write;
};

struct WIN_MOUSE_FIFO {
	unsigned short fifo[32];
	short p_read, p_write;
	POINTS pos;
};

#define BE_LEFT_BUTTON		0
#define BE_RIGHT_BUTTON		1
#define BE_MIDDLE_BUTTON	2

// sw_main.cpp
BHDLL bool InitEngine(HINSTANCE hInstance, LPCWSTR Title, int width, int height);
BHDLL void RefreshWindow();
BHDLL bool ProcessMessage(LPMSG message);
BHDLL void GetMouseInfo(MOUSE_INFO* msinf);
BHDLL void BE_Rect();

// sw_paint.cpp
BHDLL void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b);
BHDLL void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b);
BHDLL void bapi_font(int x0, int y0, int size, LPCWSTR str, char r, char g, char b, LPCWSTR font);
BHDLL void bapi_font_bk(int x0, int y0, int size, LPCWSTR str, char r, char g, char b, LPCWSTR font, char br, char bg, char bb);
BHDLL void bapi_image(int x0, int y0, int xsize, int ysize, LPCWSTR file_path);
BHDLL void bapi_icon(LPCWSTR file_path);

#elif PLATFORM == PLATFORM_XJ380

#endif

#endif