#include "managers/VolumeRecorder.h"
#include <iostream>

VolumeRecorder::VolumeRecorder() :
myVolume(0),
myLevel(Low),
myOldLevel(Low),
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

VolumeLevel VolumeRecorder::getLevel() const
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

/*bool VolumeRecorder::hasVaried() const
{
    return myVaried;
}*/

bool VolumeRecorder::OnProcessSamples(const sf::Int16* samples, size_t samplesCount)
{
    float volume = 0;
    VolumeLevel tmpLevel = Low;

    for(std::size_t i = 0; i < samplesCount; ++i)
        volume += samples[i] * samples[i];

    volume = sqrt(volume / samplesCount);

    myVolume = volume / 250.f;

    if(myVolume < Medium)
        tmpLevel = Low;
    if(myVolume >= Medium && myVolume < High)
        tmpLevel = Medium;
    if(myVolume >= High)
        tmpLevel = High;

    /*if(tmpLevel >= Medium && myOldLevel == Low)
        myVaried = true;
    else
        myVaried = false;*/

    myOldLevel = myLevel;
    myLevel    = tmpLevel;
    myUpdated  = true;
    //myVaried = myLevel != myOldLevel;

    return true;
}