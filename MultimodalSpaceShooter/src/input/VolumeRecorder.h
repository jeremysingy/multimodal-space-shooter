#ifndef VOLUMERECORDER_H
#define VOLUMERECORDER_H

#include <SFML/Audio.hpp>

namespace Volume
{
    enum Level
    {
        Low = 0,
        Medium = 35,
        High = 75
    };
}

//////////////////////////////////////////////////
/// Manage the voice events of the game using
/// the SFML library
//////////////////////////////////////////////////
class VolumeRecorder : public sf::SoundRecorder
{
    public:
        VolumeRecorder();
        ~VolumeRecorder();

        float getVolume() const;
        Volume::Level getLevel() const;
        bool hasLevelIncreased() const;
        bool hasLevelDecreased() const;

    private:
        bool OnProcessSamples(const sf::Int16* samples, std::size_t samplesCount);

        float         myVolume; 
        Volume::Level myLevel;
        Volume::Level myOldLevel;
        mutable bool  myUpdated;
};

#endif // VOLUMERECORDER_H