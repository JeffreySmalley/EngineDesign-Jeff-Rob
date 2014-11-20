#include "Controls.h"

bool Gamepads::isConnected(DWORD index)
{
	DWORD dwResult;
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	dwResult = XInputGetState(index, &state);
	if (dwResult == ERROR_SUCCESS)
		return true;
	else
		return false;
}

int Gamepads::getgamepadCount()
{
	DWORD pads;

	for (DWORD i; i < XUSER_MAX_COUNT; i++)
	{
		if (isConnected(i))
			pads++;
	}

	return pads;
}

void Gamepads::Update()
{
	pads = getgamepadCount();
}