#include "Engine.h"

Engine::Engine()
{
	
}

bool Engine::Initialize()
{
	graphics = new Graphics();
	graphics->Initilize();
	return true;
}

int Engine::Shutdown()
{

	message = graphics->Shutdown();
	delete graphics;
	graphics = 0;
	return message;
}
void Engine::Run()
{
	graphics->Run();
}