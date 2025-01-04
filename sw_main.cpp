#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
HWND XBE_hWnd;
WNDCLASSEX Window;

LRESULT CALLBACK BE_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		break;
	case WM_CHAR:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
#endif

/* 初始化 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
bool InitEngine(HINSTANCE hInstance, LPCWSTR Title, int width, int height)
{
	Window.cbSize = sizeof(Window);
	Window.style = CS_OWNDC;
	Window.lpfnWndProc = BE_WndProc;
	Window.cbClsExtra = 0;
	Window.cbWndExtra = 0;
	Window.hInstance = hInstance;
	Window.hIcon = nullptr;
	Window.hCursor = nullptr;
	Window.hbrBackground = nullptr;
	Window.lpszMenuName = nullptr;
	Window.lpszClassName = L"XJBrigeEngine";
	Window.hIconSm = nullptr;

	RegisterClassEx(&Window);

	XBE_hWnd = CreateWindowEx(
		0, L"XJBrigeEngine",
		Title,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, width, height,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(XBE_hWnd, SW_SHOW);
	RefreshWindow();
#elif PLATFORM == PLATFORM_XJ380
// XJ380
bool InitEngine() 
{
	// pass
#endif
	return true;
}

/* 刷新 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void RefreshWindow()
{
	UpdateWindow(XBE_hWnd);
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void InitEngine()
{
	// pass
#endif
	return;
}

/* 消息处理 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void ProcessMessage(LPMSG message)
{
	TranslateMessage(message);
	DispatchMessage(message);
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void ProcessMessage()
{
	// pass
#endif
	return;
}
