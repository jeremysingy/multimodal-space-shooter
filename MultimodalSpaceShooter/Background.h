#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include <SFML/Graphics.hpp>

class Background
{
    public:
        Background(const sf::Image& image, float frameTime, float imageHeight);
        
        float getFrameTime() const;
        void update();
        virtual void draw(sf::RenderTarget& window) const;
        void setImage(const sf::Image &image);
    private:
        sf::Clock                myClock;
        float                    myFrameTime;
        float                    myImageHeight;
        sf::Sprite               firstSprite;
        sf::Sprite               secondSprite;

        void setInitialPosition();
        void moveSecondBackground(int oldPosition);

};

#endif // BACKGROUND_H
