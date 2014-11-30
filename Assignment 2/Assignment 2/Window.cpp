#include "Window.h"

Window::Window()
{
}
bool Window::create(char* windowName, char* windowTitle, int posX, int posY, int width, int height)
{
	ZeroMemory(&wc,sizeof(WNDCLASSEX)); //gets the memory ready for wc

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW|CS_VREDRAW;//the window class style
	wc.lpfnWndProc = proc; // our message proccesor
	wc.hInstance = GetModuleHandle(nullptr); // gets the hinstance
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // cursor information
	//wc.hbrBackground = (HBRUSH)COLOR_WINDOW; // background brush
	wc.lpszClassName = windowName; // the window name

	RegisterClassEx(&wc); // registers wc

	//creates window
	hwnd = CreateWindowEx(NULL,
		windowName,
		windowTitle,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(nullptr),
		NULL); 
	ShowWindow(hwnd, 1); // shows the window we want, 1 enables it
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

LRESULT APIENTRY Window::proc(HWND hWndMain, UINT message, WPARAM wParam, LPARAM lParam)
{
	static POINTS ptsBegin;
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	//keyboard
	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;

		//number keys 0-9
		case  0x30:
			//0
			break;
		case  0x31:
			//1
			break;
		case  0x32:
			//2
			break;
		case  0x33:
			//3
			break;
		case  0x34:
			//4
			break;
		case  0x35:
			//5
			break;
		case  0x36:
			//6
			break;
		case  0x37:
			//7
			break;
		case  0x38:
			//8
			break;
		case  0x39:
			//9
			break;
		//letters a-z
		case 0x41:
			//a
			break;
		case 0x42:
			//b
			break;
		case 0x43:
			//c
			break;
		case 0x44:
			//d
			break;
		case 0x45:
			//e
			break;
		case 0x46:
			//f
			break;
		case 0x47:
			//g
			break;
		case 0x48:
			//h
			break;
		case 0x49:
			//i
			break;
		case 0x4A:
			//j
			break;
		case 0x4B:
			//k
			break;
		case 0x4C:
			//l
			break;
		case 0x4D:
			//m
			break;
		case 0x4E:
			//n
			break;
		case 0x4F:
			//o
			break;
		case 0x50:
			//p
			break;
		case 0x51:
			//q
			break;
		case 0x52:
			//r
			break;
		case 0x53:
			//s
			break;
		case 0x54:
			//t
			break;
		case 0x55:
			//u
			break;
		case 0x56:
			//v
			break;
		case 0x57:
			//w
			break;
		case 0x58:
			//x
			break;
		case 0x59:
			//y
			break;
		case 0x5A:
			//z
			break;
		}
		break;
			case WM_KEYUP:
		switch(wParam)
		{
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;

		//number keys 0-9
		case  0x30:
			//0
			break;
		case  0x31:
			//1
			break;
		case  0x32:
			//2
			break;
		case  0x33:
			//3
			break;
		case  0x34:
			//4
			break;
		case  0x35:
			//5
			break;
		case  0x36:
			//6
			break;
		case  0x37:
			//7
			break;
		case  0x38:
			//8
			break;
		case  0x39:
			//9
			break;

		//letters a-z
		case 0x41:
			//a
			break;
		case 0x42:
			//b
			break;
		case 0x43:
			//c
			break;
		case 0x44:
			//d
			break;
		case 0x45:
			//e
			break;
		case 0x46:
			//f
			break;
		case 0x47:
			//g
			break;
		case 0x48:
			//h
			break;
		case 0x49:
			//i
			break;
		case 0x4A:
			//j
			break;
		case 0x4B:
			//k
			break;
		case 0x4C:
			//l
			break;
		case 0x4D:
			//m
			break;
		case 0x4E:
			//n
			break;
		case 0x4F:
			//o
			break;
		case 0x50:
			//p
			break;
		case 0x51:
			//q
			break;
		case 0x52:
			//r
			break;
		case 0x53:
			//s
			break;
		case 0x54:
			//t
			break;
		case 0x55:
			//u
			break;
		case 0x56:
			//v
			break;
		case 0x57:
			//w
			break;
		case 0x58:
			//x
			break;
		case 0x59:
			//y
			break;
		case 0x5A:
			//z
			break;
		}
		break;

	//mouse
	case WM_LBUTTONDOWN:
		SetCapture(hWndMain);
		bIsCapture = true;
		ptsBegin = MAKEPOINTS(lParam);
		return 0;
	case WM_MOUSEMOVE:
		if (wParam &MK_LBUTTON)
		{
		}
		break;
	case WM_LBUTTONUP:
		ReleaseCapture();
		bIsCapture = false;
		break;
	case WM_ACTIVATEAPP:
		if (wParam = TRUE)
		{
			if(bIsCapture)
				SetCapture(hWndMain);

		}break;
	}
	return DefWindowProc(hWndMain, message, wParam, lParam);
}

int Window::getMsgPrm()
{
	return msg.wParam;
}

bool Window::bIsCapture = false;