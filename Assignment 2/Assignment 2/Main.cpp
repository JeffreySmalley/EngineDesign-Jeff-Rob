//includes our engine
#include "Engine.h"

//the main start point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	Engine* engine; //engine pointer
	engine = new Engine(); //constucts
	if (!engine)
		return 0;
	if (engine->Initialize()) //initilizeation point
		engine->Run(); //goes into our run loop

	int message = engine->Shutdown(); //when its time to shut down
	delete engine; //clears engine from memory
	engine = 0;
	return message;
}