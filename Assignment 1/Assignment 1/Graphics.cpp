#include "Graphics.h"

Graphics::Graphics()
{
}

void Graphics::Initilize()
{
	createWindow();
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
			break;
	}
}