#include <memory.h>
#include "IEventData.h"
class IEventManager
{
private:
	//typedef shared_ptr<IEventData>
public:
	//enum eConstants {}

	explicit IEventManager(const char* pName, bool setAsGlobal);
	virtual ~IEventManager();

	virtual bool VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;
	virtual bool VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type) = 0;
	virtual bool VTriggerEvent(const IEventDataPtr) const = 0;
	virtual bool VTickUpdate(unsigned long maxMillisec) = 0;
	static IEventManager* Get();

	const unsigned int EVENTMANAGER_NUM_QUEUES = 2;
};