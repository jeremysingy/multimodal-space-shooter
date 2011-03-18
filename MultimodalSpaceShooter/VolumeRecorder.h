#ifndef VOLUMERECORDER_H
#define VOLUMERECORDER_H

#include <SFML/Audio.hpp>

class VolumeRecorder : public sf::SoundRecorder 
{ 
    public: 

        float   getVolume() const {return myVolume;} 
        int     getLevel()  const {return myLevel;}  

    private:
        VolumeRecorder() : myVolume(0), myLevel(0) {} 
        ~VolumeRecorder();

        bool    OnProcessSamples(const sf::Int16* Samples, std::size_t SamplesCount); 

        float myVolume; 
        int   myLevel;

        friend class Game;
};

#endif // VOLUMERECORDER_H