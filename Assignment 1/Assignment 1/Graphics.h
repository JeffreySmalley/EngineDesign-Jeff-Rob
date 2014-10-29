#include "Window.h"
#include <d3d9.h>;

#pragma comment(lib, "d3d9.lib")
class Graphics
{
private:
	Window* window;
	bool createWindow();
public:
	Graphics();
	void Initilize();
	void Run();
};