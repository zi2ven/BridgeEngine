#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
#endif

/* 画线 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b)
{
	HDC hdc = GetDC(XBE_hWnd); // 获取窗口的DC
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b)); // 创建实线画笔
	SetBkMode(hdc, TRANSPARENT);
	HGDIOBJ hOld = SelectObject(hdc, hPen); // 将画笔选择到DC中

	// 绘图操作
	MoveToEx(hdc, x0, y0, NULL); // 移动到起始点
	LineTo(hdc, x1, y1); // 画线到(100, 100)

	// 恢复原来的对象
	SelectObject(hdc, hOld);
	DeleteObject(hPen); // 删除创建的对象，避免内存泄漏

	ReleaseDC(XBE_hWnd, hdc); // 释放DC
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b)
{
	// pass
#endif
	return;
}

/* 画椭圆 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b)
{
	HDC hdc = GetDC(XBE_hWnd); // 获取窗口的DC
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b)); // 创建实线画笔
	SetBkMode(hdc, TRANSPARENT);
	HGDIOBJ hOld = SelectObject(hdc, hPen); // 将画笔选择到DC中

	// 绘图操作
	Ellipse(hdc, x0, y0, x1, y1);

	// 恢复原来的对象
	SelectObject(hdc, hOld);
	DeleteObject(hPen); // 删除创建的对象，避免内存泄漏

	ReleaseDC(XBE_hWnd, hdc); // 释放DC
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b)
{
	// pass
#endif
	return;
}

/* 写字儿 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_font(int x0, int y0, int size, LPCWSTR str, char r, char g, char b, LPCWSTR font)
{
	HDC hdc = GetDC(XBE_hWnd); // 获取窗口的DC
	SetTextColor(hdc, RGB(r, g, b)); // 创建实线画笔
	SetBkMode(hdc, TRANSPARENT);
	HFONT hFont = CreateFont(size, 0, 
								0, 0, 
								FW_NORMAL, 
								0, 0, 0, 
								GB2312_CHARSET, 
								OUT_DEFAULT_PRECIS,
								CLIP_DEFAULT_PRECIS,
								DEFAULT_QUALITY,
								DEFAULT_PITCH | FF_DONTCARE,
								font);
	HGDIOBJ hOld = SelectObject(hdc, hFont); // 将文字选择到DC中

	// 绘图操作
	TextOut(hdc, x0, y0, str, lstrlen(str));

	// 恢复原来的对象
	SelectObject(hdc, hOld);
	DeleteObject(hFont); // 删除创建的对象，避免内存泄漏

	ReleaseDC(XBE_hWnd, hdc); // 释放DC
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_font(int x0, int y0, LPCWSTR str, char r, char g, char b)
{
	// pass
#endif
	return;
}

/* 图片 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_image(int x0, int y0, int xsize, int ysize, LPCWSTR file_path)
{
	HDC hdc = GetDC(XBE_hWnd);

	// 加载图片
	HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, 
										file_path, 
										IMAGE_BITMAP, 
										0, 0, 
										LR_LOADFROMFILE);

	// 绘制图片
	HDC memDC = CreateCompatibleDC(hdc);
	HGDIOBJ hOld = SelectObject(memDC, hBitmap);
	BitBlt(hdc, x0, y0, xsize, ysize, memDC, x0, y0, SRCCOPY);

	SelectObject(hdc, hOld);
	// 释放资源
	DeleteDC(memDC);
	DeleteObject(hBitmap);
	ReleaseDC(XBE_hWnd, hdc);
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_image(int x0, int y0, int xsize, int ysize, LPCWSTR file_path)
{
	// pass
#endif
	return;
}