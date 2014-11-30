#include "IEventManager.h"
#include "IEventData.h"
#include "BaseEventData.h"
#include "FastDelegate.h"
#include <list>
#include <map>
class EventManager : public IEventManager
{
private:
	
	typedef std::shared_ptr<IEventData> IEventDataPtr;
	void Delegate(IEventDataPtr pEventData);
	typedef fastdelegate::FastDelegate1<IEventDataPtr> EventListenerDelegate;
	
	typedef std::list<EventListenerDelegate> EventListenerList;
	typedef std::map<EventType, EventListenerList> EventListenerMap;
	typedef std::list<IEventDataPtr> EventQueue;

	EventListenerMap m_EventListeners;
	EventQueue m_queues[EVENTMANAGER_NUM_QUEUES];
	int m_activeQueue;
public:
	explicit EventManager(const char* pName, bool setAsGlobal);
	virtual ~EventManager();

	virtual bool VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type);
	virtual bool VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type);
	virtual bool VTriggerEvent(const IEventDataPtr& pEvent);
	virtual bool VQueueEvent(const IEventDataPtr& pEvent);
	virtual bool VAbortEvent(const EventType& type, bool allOfType = false);

	virtual bool VTickUpdate(unsigned long maxMillisec);
};