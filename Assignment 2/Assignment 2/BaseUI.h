#include "IGUIElement.h"
class BaseUI : public IGUIElement
{
protected:
	int posX, posY;
	int width, height;
	//optional<int> m_Result;
	bool isVisible;
public:
	BaseUI();
	virtual void OnUpdate(int){}
	virtual bool IsVisible() const {return isVisible;}
	virtual void SetVisible(bool visible) {isVisible = visible;}
};