#include "Graphics.h"

Graphics::Graphics()
{
}

void Graphics::Initilize()
{
	createWindow();
	initD3D(window->getHWND());
}
bool Graphics::createWindow()
{
	window = new Window();
	if (!window->create("Assignment1","Assignment 1", 100,100,1280,720))
		return false;

	return true;
}

void Graphics::Run()
{
	while(TRUE)
	{
		window->peekMsg();
		if(window->closeCheck())
		{
			break;
		}
	}
}

void Graphics::initD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	//rob start here
}

int Graphics::Shutdown()
{
	//delete here
	shutdownMsg=window->getMsgPrm();
	delete window;
	window = 0;
	return shutdownMsg;
}