#include "AudioChannel.h"

AudioChannel::AudioChannel(char* filePath, AudioType Type)
{
}
void AudioChannel::SetVolume(float Volume)
{
	channel->setVolume(Volume);
}
void AudioChannel::Mute()
{
	channel->setMute(true);
}
bool AudioChannel::IsComplete()
{
	delete channel;
}
int AudioChannel::GetPosition()
{
	unsigned int pos;
	FMOD_TIMEUNIT postype;
	channel->getPosition(&pos, postype);
}
void AudioChannel::Play(int LoopCount)
{
	channel->setLoopCount(LoopCount);
}
void AudioChannel::Stop()
{
	channel->stop();
}
void AudioChannel::Pause()
{
	channel->setPaused(true);
}
void AudioChannel::Resume()
{
	channel->setPaused(false);
}