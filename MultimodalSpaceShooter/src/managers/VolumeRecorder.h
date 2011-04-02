#ifndef VOLUMERECORDER_H
#define VOLUMERECORDER_H

#include <SFML/Audio.hpp>

enum VolumeLevel
{
    Low = 0,
    Medium = 35,
    High = 75
};

class VolumeRecorder : public sf::SoundRecorder
{
    public:
        VolumeRecorder();
        ~VolumeRecorder();

        float getVolume() const;
        VolumeLevel getLevel() const;
        bool hasLevelIncreased() const;
        bool hasLevelDecreased() const;

    private:
        bool OnProcessSamples(const sf::Int16* samples, std::size_t samplesCount);

        float        myVolume; 
        VolumeLevel  myLevel;
        VolumeLevel  myOldLevel;
        mutable bool myUpdated;
};

#endif // VOLUMERECORDER_H