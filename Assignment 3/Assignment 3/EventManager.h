#include "FastDelegate.h"
#include "IEventManager.h"
#include <list>
#include <map>
#define EVENTMANAGER_NUM_QUEUES 4
class EventManager : public IEventManager
{
private:
	typedef std::list<EventListenerDelegate> EventListenerList;
	typedef std::map<EventType, EventListenerList> EventListenerMap;
	typedef std::list<IEventDataPtr> EventQueue;

	EventListenerMap m_EventListeners;
	EventQueue m_queues[EVENTMANAGER_NUM_QUEUES];
	int m_activeQueue;
public:
	explicit EventManager(const char* pName, bool setAsGlobal);
	virtual ~EventManager(){}

	virtual bool VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type);
	virtual bool VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type);
	virtual bool VTriggerEvent(const IEventDataPtr& pEvent);
	virtual bool VQueueEvent(const IEventDataPtr& pEvent);
	virtual bool VAbortEvent(const EventType& type, bool allOfType = false);

	virtual bool VTickUpdate(unsigned long maxMillisec);
};