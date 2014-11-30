#ifndef I_EVENT_DATA
#define I_EVENT_DATA
#include <ostream>

class IEventData
{
protected:
	enum EventType{PLACEHOLDER_EVENT_1,PLACEHOLDER_EVENT_2,PLACEHOLDER_EVENT_3,PLACEHOLDER_EVENT_4};
public:
	virtual const EventType& VGetEventType() const = 0;
	virtual float VGetTimeStamp() const = 0;
	virtual void VSerialize(std::ostringstream out) const = 0;
	//virtual IEventData VCopy() const = 0;
	virtual const char* GetName() const = 0;
};
#endif