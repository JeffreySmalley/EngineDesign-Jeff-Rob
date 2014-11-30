/*
#include <xinput.h>
#include <dinput.h>
#include <math.h>

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


class Keyboard
{
private:
public:
	Keyboard();
};

class Mouse
{
public:
	struct Point
	{
		int x;
		int y;
	};

private:
	Point point;
public:
	
	void getPoint(Point &mousePos){ mousePos = point;}
};
*/