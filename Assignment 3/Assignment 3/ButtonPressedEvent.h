#include "BaseEventData.h"

class ButtonPressedEvent : public BaseEventData
{
private:
	//ActorId m_id; // This code is likely derived from an actor which does not exist in the context of our engine.
	// 
public:
	static const EventType sk_EventType;
	ButtonPressedEvent(std::istringstream& in);
	virtual const EventType& VGetEventType() const
	{
		return sk_EventType;
	}
	/*
	virtual IEventManager::IEventDataPtr VCopy() const
	{
		return IEventDataPtr(GCC_NEW ButtonPressedEvent());(m_id)
	}
	*/
	virtual void VSerialize(std::ostringstream &out) const
	{
		//out << m_id;
	}
	virtual const char* GetName() const
	{
		return "EventData_Button_Pressed";
	}
};