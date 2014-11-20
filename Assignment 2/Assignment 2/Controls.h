#include <xinput.h>
#include <dinput.h>

#define XUSER_MAX_COUNT 1

class Gamepads
{
private:
	int pads;
public:
	Gamepads();
	bool isConnected(DWORD index);
	int getgamepadCount();
	void Update();
};