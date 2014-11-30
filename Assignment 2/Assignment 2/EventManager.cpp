#include "EventManager.h"
#include <Windows.h>

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
	bool processed = false;

	auto findIt = m_EventListeners.find(pEvent->VGetEventType);
	if (findIt!= m_EventListeners.end())
	{
		const EventListenerList& eventListenerList = findIt->second;
		for (EventListenerList::const_iterator it = eventListenerList.begin(); it != eventListenerList.end(); ++it)
		{
			EventListenerDelegate listener = (*it);
			listener(pEvent); // Call the delegate
			processed = true;
		}
		return processed;
	}
}
bool EventManager::VQueueEvent(const IEventDataPtr& pEvent)
{
	auto findIt = m_EventListeners.find(pEvent->VGetEventType);
	if (findIt != m_EventListeners.end())
	{
		m_queues[m_activeQueue].push_back(pEvent);
		return true;
	}
	else
	{
		return false;
	}
}
bool EventManager::VAbortEvent(const EventType& type, bool allOfType)
{
	bool success = false;
	EventListenerMap::iterator findIt = m_EventListeners.find(type);

	if (findIt != m_EventListeners.end())
	{
		EventQueue& eventQueue = m_queues[m_activeQueue];
		auto it = eventQueue.begin();
		while (it != eventQueue.end())
		{
			auto thisIt = it;
			++it;
			if ((*thisIt)->VGetEventType() == type)
			{
				eventQueue.erase(thisIt);
				success = true;
				if (!allOfType)
				{
					break;
				}
			}
		}
		return success;
	}
}
bool EventManager::VTickUpdate(unsigned long maxMs)
{
	unsigned long currentMs = GetTickCount();
	unsigned long maxMs = ((maxMs == IEventManager::kINFINITE) ? (IEventManager::kINFINITE) : (currentMs + maxMs));

	// Swap active queues and clear the new queue after the swap
	int queueToProcess = m_activeQueue;
	m_activeQueue = (m_activeQueue + 1) % 2;
	m_queues[m_activeQueue].clear();

	//Process the queue
	while (!m_queues[queueToProcess].empty())
	{
		// Pop the front of the queue
		IEventDataPtr pEvent = m_queues[queueToProcess].front();
		m_queues[queueToProcess].pop_front();

		const EventType& eventType = pEvent->VGetEventType;

		// Find all the delegate functions registered for this event
		auto findIt = m_EventListeners.find(eventType);
		if (findIt != m_EventListeners.end())
		{
			const EventListenerList& eventListeners = findIt->second;
			// Call each listener
			for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it)
			{
				EventListenerDelegate listener = (*it);
				listener(pEvent);
			}
		}
		// Check to see if time ran out
		currentMs = GetTickCount();
		if (maxMs != IEventManager::kINFINITE && currentMs >= maxMs)
		{
			break;
		}
	}
	// If we couldn't process all of the events, push the remaining events to
	// the new active queue.

	bool queueFlushed = (m_queues[queueToProcess].empty());
	if (!queueFlushed)
	{
		while (!m_queues[queueToProcess].empty())
		{
			IEventDataPtr pEvent = m_queues[queueToProcess].back();
			m_queues[queueToProcess].pop_back();
			m_queues[m_activeQueue].push_back(pEvent);
		}
	}
	return queueFlushed;
}
