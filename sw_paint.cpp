#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
#endif

/* ���� */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b) {
    HDC hdc = GetDC(XBE_hWnd); // ��ȡ���ڵ�DC
    HPEN hPen =
        CreatePen(PS_SOLID, 1, RGB(r, g, b)); // ����ʵ�߻���
    SetBkMode(hdc, TRANSPARENT);
    HGDIOBJ hOld = SelectObject(hdc, hPen); // ������ѡ��DC��

    // ��ͼ����
    MoveToEx(hdc, x0, y0, NULL); // �ƶ�����ʼ��
    LineTo(hdc, x1, y1);         // ���ߵ�(100, 100)

    // �ָ�ԭ���Ķ���
    SelectObject(hdc, hOld);
    DeleteObject(
        hPen); // ɾ�������Ķ��󣬱����ڴ�й©

    ReleaseDC(XBE_hWnd, hdc); // �ͷ�DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_line(int x0, int y0, int x1, int y1, char r, char g, char b) {
    // pass
    return;
}
#endif

/* ����Բ */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b) {
    HDC hdc = GetDC(XBE_hWnd); // ��ȡ���ڵ�DC
    HPEN hPen =
        CreatePen(PS_SOLID, 1, RGB(r, g, b)); // ����ʵ�߻���
    SetBkMode(hdc, TRANSPARENT);
    HGDIOBJ hOld = SelectObject(hdc, hPen); // ������ѡ��DC��

    // ��ͼ����
    Ellipse(hdc, x0, y0, x1, y1);

    // �ָ�ԭ���Ķ���
    SelectObject(hdc, hOld);
    DeleteObject(
        hPen); // ɾ�������Ķ��󣬱����ڴ�й©

    ReleaseDC(XBE_hWnd, hdc); // �ͷ�DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_ellipse(int x0, int y0, int x1, int y1, char r, char g, char b) {
    // pass
    return;
}
#endif

/* д�ֶ� */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_font(int x0, int y0, int size, LPCWSTR str, char r, char g, char b,
               LPCWSTR font) {
    HDC hdc = GetDC(XBE_hWnd);       // ��ȡ���ڵ�DC
    SetTextColor(hdc, RGB(r, g, b)); // ����ʵ�߻���
    SetBkMode(hdc, TRANSPARENT);
    HFONT hFont =
        CreateFont(size, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET,
                   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                   DEFAULT_PITCH | FF_DONTCARE, font);
    HGDIOBJ hOld = SelectObject(hdc, hFont); // ������ѡ��DC��

    // ��ͼ����
    TextOut(hdc, x0, y0, str, lstrlen(str));

    // �ָ�ԭ���Ķ���
    SelectObject(hdc, hOld);
    DeleteObject(
        hFont); // ɾ�������Ķ��󣬱����ڴ�й©

    ReleaseDC(XBE_hWnd, hdc); // �ͷ�DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_font(int x0, int y0, LPCWSTR str, char r, char g, char b) {
    // pass
    return;
}
#endif

/* д�ֶ�����͸�������� */
#if PLATFORM == PLATFORM_WINDOWS
// Windows
void bapi_font_bk(int x0, int y0, int size, LPCWSTR str, char r, char g, char b,
                  LPCWSTR font, char br, char bg, char bb) {
    HDC hdc = GetDC(XBE_hWnd);       // ��ȡ���ڵ�DC
    SetTextColor(hdc, RGB(r, g, b)); // ����ʵ�߻���
    SetBkMode(hdc, BKMODE_LAST);
    SetBkColor(hdc, RGB(br, bg, bb));
    HFONT hFont =
        CreateFont(size, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET,
                   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                   DEFAULT_PITCH | FF_DONTCARE, font);
    HGDIOBJ hOld = SelectObject(hdc, hFont); // ������ѡ��DC��

    // ��ͼ����
    TextOut(hdc, x0, y0, str, lstrlen(str));

    // �ָ�ԭ���Ķ���
    SelectObject(hdc, hOld);
    DeleteObject(
        hFont); // ɾ�������Ķ��󣬱����ڴ�й©

    ReleaseDC(XBE_hWnd, hdc); // �ͷ�DC
    return;
}
#elif PLATFORM == PLATFORM_XJ380
// XJ380
void bapi_font_bk(int x0, int y0, LPCWSTR str, char r, char g, char b) {
    // pass
    return;
}
#endif

/* ͼƬ */
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

/* ͼ�� */
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

/* PNGͼƬ */
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