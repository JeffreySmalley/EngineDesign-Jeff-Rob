#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include <vector>
#include "AudioChannel.h"

class AudioSystem
{
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

};

enum AudioType
{
	SoundFx, Music
};

#endif