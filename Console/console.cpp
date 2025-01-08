#include <BrigeEngine.h>

// Windows Entry
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	InitEngine(hInstance, L"BirgeEngine", 800, 600);
	MSG Message;
	MOUSE_INFO msinf;
	bapi_line(100, 100, 200, 200, 0x00, 0xa2, 0xe8);
	bapi_ellipse(100, 100, 200, 200, 0x00, 0xa2, 0xe8);
	bapi_font(100, 100, 40, L"ÐÇ¼Ê¹¤×÷ÊÒ BrigeEngine", 0x00, 0xa2, 0xe8, L"Microsoft YaHei");
	bapi_image(200, 200, 326, 98, L"XINGJI.bmp");
	RefreshWindow();
	while (ProcessMessage(&Message))
	{
		GetMouseInfo(&msinf);
	}
	
	return 0;
}
