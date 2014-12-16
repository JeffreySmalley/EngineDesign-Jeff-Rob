#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include <fmod.hpp>
#include <iostream>
#include <fmod_errors.h>
#include <vector>
#include "AudioChannel.h"

class AudioSystem
{
private:
	static FMOD::System *system;
	static FMOD_RESULT result;
public:
	static std::vector <AudioChannel*> ActiveChannels;

	static void Initilize();
	static void update(float dt);
	static void Shutdown();
	static AudioChannel* PlaySound(/*resourse*/);
	static void StopSound(AudioChannel* Channel);
	static void StopAllSounds();
	static void StopSoundsOfType(AudioType Type);
	static void SetVolumeOfType(AudioType Type, float Volume);
	static void PauseAllSounds();
	static void ResumeAllSounds();
	static void MuteAll();
	static void FMODErrorCheck(FMOD_RESULT result);

};

enum AudioType
{
	SoundFx, Music
};

#endif