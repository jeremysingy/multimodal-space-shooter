#ifndef VOLUMERECORDER_H
#define VOLUMERECORDER_H

#include <SFML/Audio.hpp>

class VolumeRecorder : public sf::SoundRecorder
{
    public:
        VolumeRecorder();
        ~VolumeRecorder();

        enum SoundLevel{
            Low = 0,
            Medium = 35,
            High = 75
        };

        float getVolume() const;
        SoundLevel getLevel()  const;
        bool hasVaried() const;

    private:
        bool OnProcessSamples(const sf::Int16* samples, std::size_t samplesCount);

        float        myVolume; 
        SoundLevel   myLevel;
        SoundLevel   myOldLevel;
        bool         varied;
};

#endif // VOLUMERECORDER_H