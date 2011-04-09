#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////
/// Background of the game representing the space
//////////////////////////////////////////////////
class Background
{
    public:
        Background(const sf::Image& image, float scrollingSpeed);
        
        void update(float frameTime);
        void draw(sf::RenderTarget& window) const;

    private:
        void setInitialPosition();

        sf::Sprite myFirstSprite;
        sf::Sprite mySecondSprite;

        float myScrollingSpeed;
};

#endif // BACKGROUND_H
