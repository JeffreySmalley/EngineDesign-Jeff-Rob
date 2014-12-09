#include "IEventData.h"
#include <memory.h>
#include <iostream>

using namespace std;
class IEventManager
{
protected:
	EventType eventType;
	typedef shared_ptr<IEventData> IEventDataPtr;
	//void Delegate(IEventDataPtr pEventData);
	typedef fastdelegate::FastDelegate1<IEventDataPtr> EventListenerDelegate;
public:
	enum eConstants {kINFINITE = 0xffffffff};

	explicit IEventManager(const char* pName, bool setAsGlobal){}
	virtual ~IEventManager(){}

	virtual bool VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;
	virtual bool VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;
	virtual bool VTriggerEvent(const IEventDataPtr) const = 0;
	virtual bool VTickUpdate(unsigned long maxMillisec) = 0;
	static IEventManager* Get(){}

	//const unsigned int EVENTMANAGER_NUM_QUEUES = 2;
};