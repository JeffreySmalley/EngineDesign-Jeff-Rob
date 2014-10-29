#include <Windows.h>
#include <windowsx.h>

class Window
{
private:
	HWND hwnd;
	WNDCLASSEX wc;
	MSG msg;
	static LRESULT CALLBACK proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
public:
	Window();
	bool create(char* windowName, char* windowTitle, int posX, int posY, int width, int height);
	void peekMsg();
	bool closeCheck();
	HWND getHWND(){return hwnd;}
};