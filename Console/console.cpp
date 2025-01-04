#include <BrigeEngine.h>

// Windows Entry
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	InitEngine(hInstance, L"BirgeEngine", 800, 600);

	MSG Message;
	bapi_line(10, 10, 100, 100, 0x00, 0xa2, 0xe8);
	bapi_ellipse(10, 10, 100, 100, 0x00, 0xa2, 0xe8);
	bapi_font(10, 10, 40, L"ÐÇ¼Ê¹¤×÷ÊÒ BrigeEngine", 0x00, 0xa2, 0xe8, L"Microsoft YaHei");
	bapi_image(100, 100, 326, 98, L"G:\BrigeEngine\XINGJI.bmp");
	RefreshWindow();
	while (BE_GetMsg(&Message)) 
	{
		ProcessMessage(&Message);
	}
	
	return 0;
}
