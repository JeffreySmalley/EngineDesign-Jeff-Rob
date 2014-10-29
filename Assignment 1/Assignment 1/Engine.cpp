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

void Engine::Shutdown()
{

}
void Engine::Run()
{
	graphics->Run();
}