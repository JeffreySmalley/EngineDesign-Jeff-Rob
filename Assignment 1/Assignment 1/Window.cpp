#include "Window.h"


Window::Window()
{
}
bool Window::create(char* windowName, char* windowTitle, int posX, int posY, int width, int height)
{
	ZeroMemory(&wc,sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc = proc;
	wc.hInstance = GetModuleHandle(nullptr);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = windowName;

	RegisterClassEx(&wc);

	hwnd = CreateWindowEx(NULL,
		windowName,
		windowTitle,
		WS_OVERLAPPEDWINDOW,
		posX,
		posY,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(nullptr),
		NULL);
	ShowWindow(hwnd, 1);
	return true;
}

void Window::peekMsg()
{
	if (PeekMessage(&msg, NULL,0,0,PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

bool Window::closeCheck()
{
	return msg.message ==WM_QUIT;
}

LRESULT CALLBACK Window::proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}