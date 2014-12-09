#include "Graphics.h"

Graphics::Graphics()
{
}

void Graphics::Initialize()
{
	createWindow();
	initD3D(window->getHWND());
}
bool Graphics::createWindow()
{
	window = new Window();
	if (!window->create("FinalAssignment","Final Assignment", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT))
		return false;

	return true;
}

void Graphics::Run()
{
	while(TRUE)
	{
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
		d3ddev->BeginScene();
		// Any 3D rendering would be done here.
		d3ddev->EndScene();
		// Display the frame
		d3ddev->Present(NULL, NULL, NULL, NULL);
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
	
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	d3d->CreateDevice(D3DADAPTER_DEFAULT, 
					  D3DDEVTYPE_HAL, 
					  hWnd, 
					  D3DCREATE_SOFTWARE_VERTEXPROCESSING,
					  &d3dpp,
					  &d3ddev);
}

int Graphics::Shutdown()
{
	//delete here
	shutdownMsg=window->getMsgPrm();
	delete window;
	window = 0;
	return shutdownMsg;
}