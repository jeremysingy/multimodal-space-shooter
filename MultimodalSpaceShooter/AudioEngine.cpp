#include "AudioEngine.h"
#include "Managers.h"

AudioEngine::AudioEngine()
{
    sf::SoundBuffer buf1;
}

AudioEngine::~AudioEngine()
{
    
}

void AudioEngine::playSound(const std::string& name, float volume)
{
    std::shared_ptr<sf::SoundBuffer> buffer = soundManager().get(name);

    sf::Sound sound(*buffer);
    sound.SetVolume(volume);

    mySounds.push_back(sound);
    mySounds.back().Play();
}


