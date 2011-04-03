#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include <SFML/Graphics.hpp>

class Background : public sf::Sprite
{
    public:
        Background(const sf::Image& image, float frameTime, int myImageHeight);
        
        float getFrameTime() const;
        void update();

    private:
        sf::Clock                myClock;
        float                    myFrameTime;
        int                      myImageHeight;

        void setInitialPosition();
};

#endif // BACKGROUND_H
