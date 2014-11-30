#include "EventManager.h"

EventManager::EventManager(char const * const pName, bool setAsGlobal) : IEventManager(pName, setAsGlobal)
{
	m_activeQueue = 0;
}
bool EventManager::VAddListener(const EventListenerDelegate& eventDelegate, const EventType& type)
{
	EventListenerList& eventListenerList = m_eventListeners[type];
	for (auto it = eventListenerList.begin(); it != eventListenerList.end(); ++i)
	{
		if (eventDelegate == (*it))
		{
			GCC_WARNING("Attempting to double-register a delegate");
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
			
		}
	}
}
