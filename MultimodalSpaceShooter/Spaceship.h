#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Entity.h"
#include "EventListener.h"
#include <SFML/Graphics.hpp>

class Spaceship : public Entity, public EventListener
{
    public:
        Spaceship();
        ~Spaceship();

        virtual void onEvent(const sf::Event& event);
        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;

    private:
        void fireMissile();

        sf::Sprite mySprite;

        static const float SPEED;
};

#endif // SPACESHIP_H