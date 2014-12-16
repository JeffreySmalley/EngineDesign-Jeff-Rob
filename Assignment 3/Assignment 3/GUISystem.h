#include "Controls.h"
#include "GUIStateManager.h"
#include "IGUIElement.h"
#include <list>
class GUISystem
{
private:
	GUIStateManager* stateManager;
	//IGUIElement* elements;
	int screenSizeX,screenSizeY;
	int message; // for shutdown
	Gamepads gamepadInput;
	

public:
	std::list<IGUIElement> elements;
	
	GUISystem();
	bool Initialize();
	int Shutdown();
	void Update(float dt);
	//void Render();
	void AddElement(IGUIElement e);
	void RemoveElement(IGUIElement e);
};
