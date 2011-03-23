#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "entities/Entity.h"
#include "utils/AnimatedSprite.h"
#include <SFML/Graphics.hpp>

class Explosion : public Entity
{
    public:
        Explosion(const sf::Vector2f& initialPos);
        virtual ~Explosion();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;
        virtual sf::FloatRect getBoundingRect() const;

    private:
        AnimatedSprite mySprite;
        sf::Clock      myClock;
};

#endif // EXPLOSION_H