#include "AudioSystem.h"

void AudioSystem::Initilize()
{
	result = FMOD::System_Create(&system);
	FMODErrorCheck(result);

	result = system->init(512,FMOD_INIT_NORMAL,0);

	FMODErrorCheck(result);
}

void AudioSystem::update(float dt)
{
	system->update();
}
void AudioSystem::Shutdown()
{
	for (int i = 0; i<ActiveChannels.size(); i++)
	{
		delete ActiveChannels[i];
	}

	delete system;
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

void AudioSystem::FMODErrorCheck(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        std::cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << std::endl;
        exit(-1);
    }
}