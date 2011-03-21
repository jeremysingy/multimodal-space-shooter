#include "VolumeRecorder.h"
#include <iostream>

VolumeRecorder::VolumeRecorder() : myVolume(0), myLevel(Low)
{

}

VolumeRecorder::~VolumeRecorder()
{

}

float VolumeRecorder::getVolume() const
{
    return myVolume;
}

VolumeRecorder::SoundLevel VolumeRecorder::getLevel() const
{
    return myLevel;
}

bool VolumeRecorder::hasVaried() const
{
    return varied;
}

bool VolumeRecorder::OnProcessSamples(const sf::Int16* samples, size_t samplesCount)
{
    float       volume = 0;
    SoundLevel  tmpLevel = Low;

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

    if(tmpLevel >= Medium && myOldLevel == Low){
        varied = true;
    }
    else{
        varied = false;
    }

    myOldLevel = myLevel;
    myLevel    = tmpLevel;

    return true;
}