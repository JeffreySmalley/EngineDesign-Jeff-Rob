#include <xinput.h>
#include <dinput.h>
#include <math.h>
#include <atltypes.h>
#include <string>

#pragma comment(lib, "Xinput9_1_0.lib")

#define XUSER_MAX_COUNT 1
#define XINPUT_MAX_TRIGGER_DISTANCE 255
#define XINPUT_FLOAT_MAX 32767
#define XINPUT_DEADZONE 7849
#define XINPUT_TRIGGER_THRESHOLD 15

class Gamepads
{
private:
	float LX,LY,LMagnitude;
	float RX,RY,RMagnitude;
	float normalizedLX,normalizedLY;
	float normalizedRX,normalizedRY;
	float normalizedRMagnitude,normalizedLMagnitude;
	bool AButton,BButton,XButton,YButton,RButton,LButton,LSButton,RSButton,StartButton,BackButton;
	int RTrigger,LTrigger;
	int pads;
	XINPUT_STATE gamepadState;
public:
	Gamepads();
	bool isConnected(DWORD index);
	int getgamepadCount();
	void Update();
};


class IEKeyBoardHandler
{
	virtual bool VOnKeyDown(unsigned int const kcode)=0;
	virtual bool VOnKeyUp(unsigned int const kcode)=0;
};

class IPointerHandler
{
public:
	virtual bool VOnPointerMove(const CPoint &mousePos)=0;
	virtual bool VOnPointerButtonDown(const CPoint &mousePos, const std::string &buttonName)=0;
	virtual bool VOnPointerButtonUp(const CPoint &mousePos, const std::string &buttonName)=0;
	virtual int VGetPointerRadius()=0;
};

class IJoystickHandler
{
	virtual bool VOnButtonDown(const std::string &buttonName, int const pressure)=0;
	virtual bool VOnButtonUp(const std::string &buttonName)=0;
	virtual bool VOnJoyStrick(float const x, float const y)=0;
};

class IGamepadHandler
{
	virtual bool VOnTrigger(const std::string &triggerName, float const pressure)=0;
	virtual bool VOnButtonDown(const std::string &buttonName, int const pressure)=0;
	virtual bool VOnButtonUp(const std::string &buttonName, int const pressure)=0;
	virtual bool VOnDirectionalPad(const std::string &stickName, float const x, float const y)=0;
};