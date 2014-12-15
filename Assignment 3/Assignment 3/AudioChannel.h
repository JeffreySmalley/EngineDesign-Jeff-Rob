#ifndef AUDIOCHANNEL_H
#define AUDIOCHANNEL_H

#include "AudioSystem.h"
class AudioChannel
{
private:
	float Volume;
	bool IsLooping;
	bool IsPaused;
	AudioType Type;
public:
	AudioChannel(/*resourse*/ AudioType Type);
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