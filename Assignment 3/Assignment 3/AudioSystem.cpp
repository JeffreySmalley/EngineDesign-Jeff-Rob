#include "AudioSystem.h"

void AudioSystem::Initilize()
{
	
}

void AudioSystem::update(float dt)
{
}
void AudioSystem::Shutdown()
{
	for (int i = 0; i<ActiveChannels.size(); i++)
	{
		delete ActiveChannels[i];
	}
}
void AudioSystem::StopSound(AudioChannel* Channel)
{
	Channel->Stop();
}
void AudioSystem::StopAllSounds()
{
	for (int i = 0; i < ActiveChannels.size();i++)
	{
		ActiveChannels[i]->Stop();
	}
}
void AudioSystem::StopSoundsOfType(AudioType Type)
{
	for (int i = 0; i < ActiveChannels.size();i++)
	{
		if (ActiveChannels[i]->getType() == Type)
		{
			ActiveChannels[i]->Stop();
		}
	}
}
void AudioSystem::SetVolumeOfType(AudioType Type, float Volume)
{
	for (int i = 0; i < ActiveChannels.size();i++)
	{
		if (ActiveChannels[i]->getType() == Type)
		{
			ActiveChannels[i]->SetVolume(Volume);
		}
	}
}
void AudioSystem::PauseAllSounds()
{
	for (int i = 0; i < ActiveChannels.size();i++)
	{
		ActiveChannels[i]->Pause();
	}
}
void AudioSystem::ResumeAllSounds()
{
	for (int i = 0; i < ActiveChannels.size();i++)
	{
		ActiveChannels[i]->Resume();
	}
}
void AudioSystem::MuteAll()
{
	for (int i = 0; i < ActiveChannels.size();i++)
	{
		ActiveChannels[i]->Mute();
	}
}