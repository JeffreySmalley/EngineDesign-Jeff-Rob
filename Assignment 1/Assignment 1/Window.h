#include <Windows.h>
#include <windowsx.h>

class Window
{
private:
	HWND hwnd; //hwindow information
	WNDCLASSEX wc; //window class information
	MSG msg; //message
	static LRESULT CALLBACK proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam); //the process that reads messages
public:
	Window(); //constructor
	bool create(char* windowName, char* windowTitle, int posX, int posY, int width, int height); //called to create the window
	void peekMsg(); //peeks to see if there is a message, rather than checking for  a better  fps
	bool closeCheck(); //checks to see if the window has been closed
	HWND getHWND(){return hwnd;} //so we can hook into the window from outside
	int getMsgPrm();//to get the window message prm
};