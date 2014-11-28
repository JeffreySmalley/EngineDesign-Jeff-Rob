#include "GUIStateManager.h"

void GUIStateManager::SetState(states s)
{
	switch (s)
	{
	case STATE1:
		s=STATE1;
		break;
	case STATE2:
		s=STATE2;
		break;
	case STATE3:
		s=STATE3;
		break;
	case STATE4:
		s=STATE4;
		break;
	}
}

void GUIStateManager::GetState()