#include "input/VolumeRecorder.h"

VolumeRecorder::VolumeRecorder() :
myVolume(0),
myLevel(Volume::Low),
myOldLevel(Volume::Low),
myUpdated(false)
{

}

VolumeRecorder::~VolumeRecorder()
{

}

float VolumeRecorder::getVolume() const
{
    return myVolume;
}

Volume::Level VolumeRecorder::getLevel() const
{
    return myLevel;
}

bool VolumeRecorder::hasLevelIncreased() const
{
    if(!myUpdated)
        return false;

    myUpdated = false;
    
    return myLevel > myOldLevel;
}

bool VolumeRecorder::hasLevelDecreased() const
{
    return myLevel < myOldLevel;
}

bool VolumeRecorder::OnProcessSamples(const sf::Int16* samples, size_t samplesCount)
{
    float volume = 0;
    Volume::Level tmpLevel = Volume::Low;

    for(std::size_t i = 0; i < samplesCount; ++i)
        volume += samples[i] * samples[i];

    volume = sqrt(volume / samplesCount);

    myVolume = volume / 250.f;

    if(myVolume < Volume::Medium)
        tmpLevel = Volume::Low;
    if(myVolume >= Volume::Medium && myVolume < Volume::High)
        tmpLevel = Volume::Medium;
    if(myVolume >= Volume::High)
        tmpLevel = Volume::High;

    myOldLevel = myLevel;
    myLevel    = tmpLevel;
    myUpdated  = true;

    return true;
}