#include "Window.h"
#include <d3d9.h>;

#pragma comment(lib, "d3d9.lib")
class Graphics
{
private:
	int shutdownMsg; //holds the shutdown message
	Window* window; //window pointer
	LPDIRECT3D9 d3d; //d3d information
	LPDIRECT3DDEVICE9 d3ddev; //device information
	void initD3D(HWND hWnd); // initilizezes the d3d
	void render(void); //updates the renderer
	void clean(void); // for shudown, so we can srub the memory
	bool createWindow(); //to create the window
public:
	Graphics(); //constructor
	void Initialize(); //initilizes graphics
	void Run(); // goes into our loop
	int Shutdown(); //the shutdown
};