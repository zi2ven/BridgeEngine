#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
HWND XBE_hWnd;
WNDCLASSEX Window;
HINSTANCE XBE_hInstance;
WIN_KEY_FIFO inkeyc;
WIN_MOUSE_FIFO inmousec;

LRESULT CALLBACK BE_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	wchar_t str;
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
		inkeyc.fifo[inkeyc.p_write] = (unsigned short)(wParam);
		if (inkeyc.p_write == 31) {
			inkeyc.p_write = -1;
		}
		inkeyc.p_write++;
		break;
	case WM_LBUTTONDOWN:
		inmousec.fifo[inkeyc.p_write] = BE_LEFT_BUTTON;
		inmousec.p_write++;
		if (inmousec.p_write == 31) {
			inmousec.p_write = 0;
		}
		break;
	case WM_MBUTTONDOWN:
		inmousec.fifo[inkeyc.p_write] = BE_MIDDLE_BUTTON;
		inmousec.p_write++;
		if (inmousec.p_write == 31) {
			inmousec.p_write = 0;
		}
		break;
	case WM_RBUTTONDOWN:
		inmousec.fifo[inkeyc.p_write] = BE_RIGHT_BUTTON;
		inmousec.p_write++;
		if (inmousec.p_write == 31) {
			inmousec.p_write = 0;
		}
		break;
	case WM_MOUSEMOVE:
		inmousec.pos = MAKEPOINTS(lParam);
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
	XBE_hInstance = hInstance;

	inkeyc.p_read = 0;
	inkeyc.p_write = 0;
	inmousec.p_read = 0;
	inmousec.p_write = 0;

	RegisterClassEx(&Window);

	XBE_hWnd = CreateWindowEx(
		0, L"XJBrigeEngine",
		Title,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | SS_BITMAP,
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
bool ProcessMessage(LPMSG message)
{
	TranslateMessage(message);
	DispatchMessage(message);
	return GetMessage(message, nullptr, 0, 0);
#elif PLATFORM == PLATFORM_XJ380
// XJ380
bool ProcessMessage()
{
	// pass
#endif
}

/* 鼠标坐标 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void GetMouseInfo(MOUSE_INFO* msinf)
{
	msinf->x = inmousec.pos.x;
	msinf->y = inmousec.pos.y;
	switch(inmousec.fifo[inmousec.p_read]) 
	{
	case BE_LEFT_BUTTON:
		msinf->lb = true;
		break;
	case BE_RIGHT_BUTTON:
		msinf->rb = true;
		break;
	case BE_MIDDLE_BUTTON:
		msinf->mb = true;
		break;
	}
	return;
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void GetMouseInfo()
{
	// pass
#endif
}
