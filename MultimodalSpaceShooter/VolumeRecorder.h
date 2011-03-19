#ifndef VOLUMERECORDER_H
#define VOLUMERECORDER_H

#include <SFML/Audio.hpp>

class VolumeRecorder : public sf::SoundRecorder
{
    public:
        VolumeRecorder();
        ~VolumeRecorder();

        float getVolume() const;
        int getLevel()  const;

        bool OnProcessSamples(const sf::Int16* samples, std::size_t samplesCount);

        float myVolume; 
        int   myLevel;
};

#endif // VOLUMERECORDER_H