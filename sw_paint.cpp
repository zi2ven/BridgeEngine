#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
#endif

/* 画线 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b) {
    HDC hdc = GetDC(XBE_hWnd);                        // 获取窗口的DC
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b)); // 创建实线画笔
    SetBkMode(hdc, TRANSPARENT);
    HGDIOBJ hOld = SelectObject(hdc, hPen); // 将画笔选择到DC中

    // 绘图操作
    MoveToEx(hdc, x0, y0, NULL); // 移动到起始点
    LineTo(hdc, x1, y1);         // 画线到(100, 100)

    // 恢复原来的对象
    SelectObject(hdc, hOld);
    DeleteObject(hPen); // 删除创建的对象，避免内存泄漏

    ReleaseDC(XBE_hWnd, hdc); // 释放DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b) {
    // pass
    return;
}
#endif

/* 画椭圆 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b) {
    HDC hdc = GetDC(XBE_hWnd);                        // 获取窗口的DC
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b)); // 创建实线画笔
    SetBkMode(hdc, TRANSPARENT);
    HGDIOBJ hOld = SelectObject(hdc, hPen); // 将画笔选择到DC中

    // 绘图操作
    Ellipse(hdc, x0, y0, x1, y1);

    // 恢复原来的对象
    SelectObject(hdc, hOld);
    DeleteObject(hPen); // 删除创建的对象，避免内存泄漏

    ReleaseDC(XBE_hWnd, hdc); // 释放DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b) {
    // pass
    return;
}
#endif

/* 写字儿 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_font(int x0, int y0, int size, LPCWSTR str, char r, char g, char b,
               LPCWSTR font) {
    HDC hdc = GetDC(XBE_hWnd);       // 获取窗口的DC
    SetTextColor(hdc, RGB(r, g, b)); // 创建实线画笔
    SetBkMode(hdc, TRANSPARENT);
    HFONT hFont =
        CreateFont(size, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET,
                   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                   DEFAULT_PITCH | FF_DONTCARE, font);
    HGDIOBJ hOld = SelectObject(hdc, hFont); // 将文字选择到DC中

    // 绘图操作
    TextOut(hdc, x0, y0, str, lstrlen(str));

    // 恢复原来的对象
    SelectObject(hdc, hOld);
    DeleteObject(hFont); // 删除创建的对象，避免内存泄漏

    ReleaseDC(XBE_hWnd, hdc); // 释放DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_font(int x0, int y0, LPCWSTR str, char r, char g, char b) {
    // pass
    return;
}
#endif

/*  写字儿（非透明背景） */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_font_bk(int x0, int y0, int size, LPCWSTR str, char r, char g, char b,
                  LPCWSTR font, char br, char bg, char bb) {
    HDC hdc = GetDC(XBE_hWnd);       // 获取窗口的DC
    SetTextColor(hdc, RGB(r, g, b)); // 创建实线画笔
    SetBkMode(hdc, BKMODE_LAST);
    SetBkColor(hdc, RGB(br, bg, bb));
    HFONT hFont =
        CreateFont(size, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET,
                   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                   DEFAULT_PITCH | FF_DONTCARE, font);
    HGDIOBJ hOld = SelectObject(hdc, hFont); // 将文字选择到DC中

    // 绘图操作
    TextOut(hdc, x0, y0, str, lstrlen(str));

    // 恢复原来的对象
    SelectObject(hdc, hOld);
    DeleteObject(hFont); // 删除创建的对象，避免内存泄漏

    ReleaseDC(XBE_hWnd, hdc); // 释放DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_font_bk(int x0, int y0, LPCWSTR str, char r, char g, char b) {
    // pass
    return;
}
#endif

/* 图片 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_image(int x0, int y0, int xsize, int ysize, LPCWSTR file_path) {
    HBITMAP Image;
    HWND hImage;
    Image = (HBITMAP)LoadImage(NULL, file_path, IMAGE_BITMAP, xsize, ysize,
                               LR_LOADFROMFILE);
    hImage =
        CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, x0,
                      y0, xsize, ysize, XBE_hWnd, nullptr, nullptr, nullptr);
    SendMessageW(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)(Image));
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_image(int x0, int y0, int xsize, int ysize, LPCWSTR file_path) {
    // pass
    return;
}
#endif

/* 图标 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_icon(LPCWSTR file_path) {
    HBITMAP Image;
    HWND hImage;
    Image =
        (HBITMAP)LoadImage(NULL, file_path, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    hImage = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_ICON, 0,
                           0, 64, 64, XBE_hWnd, nullptr, nullptr, nullptr);
    SendMessageW(hImage, STM_SETICON, IMAGE_ICON, (LPARAM)(Image));
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_icon(int x0, int y0, int xsize, int ysize, LPCWSTR file_path) {
    // pass
    return;
}
#endif

/* PNG图片 */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_png(int x0, int y0, int xsize, int ysize, LPCWSTR file_path) {
    HBITMAP Image;
    HWND hImage;
    Image = LoadBitmapFromResource(file_path);
    hImage =
        CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, x0,
                      y0, xsize, ysize, XBE_hWnd, nullptr, nullptr, nullptr);
    SendMessageW(hImage, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)(Image));
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_png(int x0, int y0, int xsize, int ysize, LPCWSTR file_path) {
    // pass
    return;
}
#endif