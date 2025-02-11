#include "BrigeEngine.h"
#include "compile_set.h"

#if PLATFORM == PLATFORM_WINDOWS
#include <iostream>
#endif

#if PLATFORM == PLATFORM_WINDOWS
BHDLL HBITMAP LoadBitmapFromResource(LPCWSTR PicName, bool transparent) {
    HANDLE hGlobal = NULL;
    ULONG_PTR GDIToken = 0;
    Gdiplus::Image *Img = NULL;
    Gdiplus::GdiplusStartupInput GDIStartInput = NULL;

    Gdiplus::GdiplusStartup(&GDIToken, &GDIStartInput, NULL);

    HANDLE hFile = CreateFile(PicName, GENERIC_READ | GENERIC_WRITE, NULL, NULL,
                              OPEN_ALWAYS, NULL, NULL);
    HRSRC hResource = NULL;
    DWORD readCount = 0;
    bool temp = ReadFile(hFile, hResource, 33185792, &readCount, NULL);
    if (!hResource) {
        return NULL;
    }

    HGLOBAL hFileResource = LoadResource(NULL, hResource);
    if (!hFileResource) {
        return NULL;
    }

    LPVOID lpFile = LockResource(hFileResource);
    if (!lpFile) {
        return NULL;
    }

    DWORD dwSize = SizeofResource(NULL, hResource);
    if (!dwSize) {
        return NULL;
    }

    void *data = LockResource(hFileResource);
    if (!data) {
        return NULL;
    }

    IStream *pStream = NULL;
    hGlobal = GlobalAlloc(GMEM_FIXED, dwSize);

    memcpy(hGlobal, data, dwSize);
    UnlockResource(hFileResource);
    FreeResource(hFileResource);

    if (CreateStreamOnHGlobal(hGlobal, true, &pStream) == S_OK) {
        Img = new Gdiplus::Image(pStream, false);
        pStream->Release();
        GlobalFree(hGlobal);
        hGlobal = NULL;

        HBITMAP hBitmap = NULL;
        static_cast<Gdiplus::Bitmap *>(Img)->GetHBITMAP(
            transparent ? Gdiplus::Color::Transparent : Gdiplus::Color(0, 0, 0),
            &hBitmap);

        delete Img;
        Gdiplus::GdiplusShutdown(GDIToken);
        GDIStartInput = NULL;
        GDIToken = 0;

        return hBitmap;
    }

    GlobalFree(hGlobal);
    hGlobal = NULL;
    Gdiplus::GdiplusShutdown(GDIToken);
    GDIStartInput = NULL;
    GDIToken = 0;

    return NULL;
}
#endif

void printcon(const char *str) {
#if PLATFORM == PLATFORM_WINDOWS
    // Windows
    std::cout << str << std::endl;
#elif PLATFORM == PLATFORM_XJ380
    // XJ380
#endif
    return;
}

void inputcon(char *str) {
#if PLATFORM == PLATFORM_WINDOWS
    // Windows
    std::cin >> str;
#elif PLATFORM == PLATFORM_XJ380
    // XJ380
#endif
    return;
}
