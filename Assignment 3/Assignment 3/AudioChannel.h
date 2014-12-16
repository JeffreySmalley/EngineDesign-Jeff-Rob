#ifndef AUDIOCHANNEL_H
#define AUDIOCHANNEL_H
#include "AudioSystem.h"
class AudioChannel
{
private:
	FMOD::Channel* channel;
	float Volume;
	bool IsLooping;
	bool IsPaused;
	AudioType Type;
public:
	AudioChannel(char* filePath, AudioType Type);
	void SetVolume(float Volume);
	void Mute();
	bool IsComplete();
	int GetPosition();
	void Play(int LoopCount);
	void Stop();
	void Pause();
	void Resume();
	AudioType getType() { return Type;}
};

#endif