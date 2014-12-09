#include "Engine.h"

Engine::Engine()
{
	
}

bool Engine::Initialize()
{
	graphics = new Graphics();
	graphics->Initialize();
	return true;
}

int Engine::Shutdown()
{
	message = graphics->Shutdown();
	delete graphics;
	return message;
}
void Engine::Run()
{
	graphics->Run();
}