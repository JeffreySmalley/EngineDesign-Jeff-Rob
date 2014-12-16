
#include "GUISystem.h"

GUISystem::GUISystem()
{
	
}
bool GUISystem::Initialize()
{
	return true;
}
int GUISystem::Shutdown()
{
	delete stateManager;
	//delete elements;
	return true;
}
void GUISystem::AddElement(IGUIElement e)
{
	elements.push_back(e);
}
void GUISystem::RemoveElement(IGUIElement e)
{
	//elements.remove(e);
}
