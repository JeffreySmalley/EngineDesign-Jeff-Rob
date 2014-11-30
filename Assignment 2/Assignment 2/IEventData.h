#ifndef I_EVENT_DATA
#define I_EVENT_DATA
#include "EventType.h"
#include <ostream>
#include <memory>
#include <list>

class IEventData
{
public:
	virtual const EventType& VGetEventType(void) = 0;
	virtual float VGetTimeStamp() const = 0;
	virtual void VSerialize(std::ostringstream out) const = 0;
	//virtual IEventData VCopy() const = 0;
	virtual const char* GetName() const = 0;
};
#endif