#include "Graphics.h"

class Engine
{
private:
	Graphics* graphics; // graphics pointer
	int message; //only for shutdown
public:
	Engine(); //constructor
	bool Initialize(); // for any initilizeations
	void Run(); //starts the engine
	int Shutdown(); //shuts down engine
};