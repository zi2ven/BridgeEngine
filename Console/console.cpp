#include <BrigeEngine.h>
#include <compile_set.h>

#if PLATFORM == PLATFORM_WINDOWS
// Windows Entry
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd) {
    InitEngine(hInstance, L"BirgeEngine", 1600, 900);
    MSG Message;
    MOUSE_INFO msinf;
    bapi_line(100, 100, 200, 200, 0x00, 0xa2, 0xe8);
    bapi_ellipse(100, 100, 200, 200, 0x00, 0xa2, 0xe8);
    bapi_font(100, 100, 40, L"ÐÇ¼Ê¹¤×÷ÊÒ BrigeEngine", 0x00, 0xa2, 0xe8,
              L"Microsoft YaHei");
    bapi_image(200, 200, 326, 98, L"XINGJI.bmp");
    bapi_png(400, 400, 326, 98, L"XINGJI.png");
    InitMap(".");
    RefreshWindow();
    while (ProcessMessage(&Message)) {
        GetMouseInfo(&msinf);
    }

    return 0;
}
#elif PLATFORM == PLATFORM_LINUX
// Linux Entry
int main(int argc, char *argv[]) { return 0; }
#endif
