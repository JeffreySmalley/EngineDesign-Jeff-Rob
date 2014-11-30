#include "EventManager.h"

EventManager::EventManager(char const * const pName, bool setAsGlobal) : IEventManager(pName, setAsGlobal)
{
	m_activeQueue = 0;
}

bool EventManager::VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type)
{
	EventListenerList& eventListenerList = m_EventListeners[type];
	for (auto it = eventListenerList.begin(); it != eventListenerList.end(); ++it)
	{
		if (eventDelegate == (*it))
		{
			//GCC_WARNING("Attempting to double-register a delegate");
			return false;
		}
	}
	eventListenerList.push_back(eventDelegate);
	return true;
}
bool EventManager::VRemoveListener(const EventListenerDelegate& eventDelegate, const EventType& type)
{
	bool success = false;

	auto findIt = m_EventListeners.find(type);
	if (findIt != m_EventListeners.end())
	{
		EventListenerList& listeners = findIt->second;
		for (auto it = listeners.begin(); it != listeners.end(); ++it)
		{
			if (eventDelegate==(*it))
			{
				listeners.erase(it);
				// We don't need to continue because it should be impossible for
				// The same delegate function to be registered for the same event
				// more than once.
				success=true;
				break;
			}
		}
	}
	return success;
}
bool EventManager::VTriggerEvent(const IEventDataPtr& pEvent)
{
	return true;
}
bool EventManager::VQueueEvent(const IEventDataPtr& pEvent)
{
	return true;
}
bool EventManager::VAbortEvent(const EventType& type, bool allOfType)
{
	return true;
}
bool EventManager::VTickUpdate(unsigned long maxMillisec)
{
	return true;
}
