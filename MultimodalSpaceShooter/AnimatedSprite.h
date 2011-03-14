#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite
{
    public:
        AnimatedSprite(const sf::Image& image, unsigned int frameWidth, unsigned int frameHeight, float frameTime);
        
        float getFrameTime() const;
        unsigned int getNbFrames() const;
        void update();

    private:
        std::vector<sf::IntRect> myFrames;
        sf::Clock                myClock;
        float                    myFrameTime;
        unsigned int             myCrtFrame;
};

#endif // ANIMATEDSPRITE_H