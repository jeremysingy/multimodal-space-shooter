#ifndef FIRE_H
#define FIRE_H

#include "entities/Entity.h"
#include "utils/AnimatedSprite.h"
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////
/// Fire when the spaceship launches missiles
//////////////////////////////////////////////////
class Fire : public Entity
{
    public:
        Fire();
        virtual ~Fire();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;
        virtual sf::FloatRect getBoundingRect() const;
        
        void setOnFire(bool value);
        
        void setPosition(float x, float y);

    private:
        bool onFire;

        AnimatedSprite mySprite;
        sf::Clock      myClock;
};

#endif // FIRE_H
