#include "Graphics.h"

class Engine
{
private:
	Graphics* graphics;
public:
	Engine();
	bool Initialize();
	void Run();
	void Shutdown();
};