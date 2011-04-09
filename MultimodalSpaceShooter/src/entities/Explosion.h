#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "entities/Entity.h"
#include "utils/AnimatedSprite.h"
#include <string>
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////
/// Explosion entity, when a planet or another
/// object is destroyed
//////////////////////////////////////////////////
class Explosion : public Entity
{
    public:
        static const sf::Vector2f FRAME_SIZE;

        Explosion(const sf::Vector2f& initialPos);

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;
        virtual sf::FloatRect getBoundingRect() const;

    private:

        AnimatedSprite mySprite;
        sf::Clock      myClock;
};

#endif // EXPLOSION_H