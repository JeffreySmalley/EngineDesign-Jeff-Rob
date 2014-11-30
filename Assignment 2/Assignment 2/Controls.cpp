#include "Controls.h"

Gamepads::Gamepads()
{
	LX=LY=RX=RY=normalizedLX=normalizedLY=normalizedRX=normalizedRY=RTrigger=LTrigger=0;
	AButton=BButton=XButton=YButton=RButton=LButton=LSButton=RSButton=StartButton=BackButton=false;
	normalizedRMagnitude=normalizedLMagnitude=0;
}

bool Gamepads::isConnected(DWORD index)
{
	DWORD dwResult;
	SecureZeroMemory(&gamepadState, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(index, &gamepadState);
	if (dwResult == ERROR_SUCCESS)
		return true;
	else
		return false;
}

int Gamepads::getgamepadCount()
{
	DWORD pads = 0;

	for (DWORD i = 0; i < XUSER_MAX_COUNT; i++)
	{
		if (isConnected(i))
			pads++;
	}

	return pads;
}



void Gamepads::Update()
{
	pads = getgamepadCount();
	//SecureZeroMemory(&gamepadState, sizeof(XINPUT_STATE));
	DWORD result;
	for (int i=0;i<pads;i++)
	{
		if(XInputGetState(i,&gamepadState) == ERROR_SUCCESS)
		{
			LX = gamepadState.Gamepad.sThumbLX;
			LY = gamepadState.Gamepad.sThumbLY;
			
			LMagnitude = sqrt(LX*LX + LY*LY);

			RX = gamepadState.Gamepad.sThumbRX;
			RY = gamepadState.Gamepad.sThumbRY;

			RMagnitude = sqrt(RX*RX + RY*RY);

			normalizedLX = LX / LMagnitude;

			if (RMagnitude > XINPUT_DEADZONE)
			{
				if(RMagnitude > XINPUT_FLOAT_MAX) RMagnitude = XINPUT_FLOAT_MAX;
				RMagnitude -= XINPUT_DEADZONE;
				normalizedRMagnitude = RMagnitude / (XINPUT_FLOAT_MAX - XINPUT_DEADZONE);
			}
			else 
			{
				RMagnitude = 0;
				normalizedRMagnitude = 0;
			}
			if (LMagnitude > XINPUT_DEADZONE)
			{
				if(LMagnitude > XINPUT_FLOAT_MAX) LMagnitude = XINPUT_FLOAT_MAX;
				LMagnitude -= XINPUT_DEADZONE;
				normalizedLMagnitude = LMagnitude / (XINPUT_FLOAT_MAX - XINPUT_DEADZONE);
			}
			else 
			{
				LMagnitude = 0;
				normalizedLMagnitude = 0;
			}
			AButton=((gamepadState.Gamepad.wButtons & XINPUT_GAMEPAD_A)!=0);
		}
	}
}