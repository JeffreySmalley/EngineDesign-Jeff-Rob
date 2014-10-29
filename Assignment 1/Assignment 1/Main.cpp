#include "Engine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Engine* engine;
	engine = new Engine();
	if (!engine)
		return 0;
	if (engine->Initialize())
		engine->Run();

	engine->Shutdown();
	delete engine;
	engine = 0;
	return 0;
}