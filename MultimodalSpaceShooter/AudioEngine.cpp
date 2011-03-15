#include "AudioEngine.h"
#include "Managers.h"
#include <iostream>

AudioEngine::AudioEngine() 
{

}

AudioEngine::~AudioEngine()
{

}

void AudioEngine::playSound(const std::string& name, float volume)
{
	std::shared_ptr<sf::SoundBuffer> buffer = soundManager().get(name);
	sf::Sound sound;
	sound.SetBuffer(*buffer);
	sound.SetLoop(false);
	sound.SetVolume(volume);
	mySounds.push_back(sound);
	mySounds.back().Play();
}

