#include "core/AudioEngine.h"
#include "core/Managers.h"

AudioEngine::AudioEngine() :
mySounds(MAX_SOUNDS),
myNextSoundId(0)
{
    // To avoid these ugly OpenAL messages...
    //sf::SoundBuffer dummyBuffer;
}

AudioEngine::~AudioEngine()
{
    
}

void AudioEngine::playSound(const std::string& name, float volume)
{
    std::shared_ptr<sf::SoundBuffer> buffer = soundManager().get(name);

    mySounds[myNextSoundId].Stop();
    mySounds[myNextSoundId].SetBuffer(*buffer);
    mySounds[myNextSoundId].SetVolume(volume);
    mySounds[myNextSoundId].Play();

    myNextSoundId = (myNextSoundId + 1) % MAX_SOUNDS;
}


