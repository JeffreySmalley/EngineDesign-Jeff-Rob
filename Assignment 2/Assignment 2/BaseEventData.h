#include "IEventData.h"

class BaseEventData : public IEventData
{
private:
	const float m_timeStamp;
public:
	explicit BaseEventData(const float timeStamp = 0.0f) : m_timeStamp(timeStamp){}
	virtual ~BaseEventData();
	// Returns the type of event
	virtual const EventType& VGetEventType(void) const = 0;
	
};