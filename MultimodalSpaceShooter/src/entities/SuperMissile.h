#ifndef SUPERMISSILE_H
#define SUPERMISSILE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////
/// Super missiles launched by the spaceship
//////////////////////////////////////////////////
class SuperMissile : public Entity
{
    public:
        SuperMissile(const sf::Vector2f& initialPosition, float angle);
        virtual ~SuperMissile();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;
        virtual void onCollision(Object::Type otherType, const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;

    private:
        float myAngle;
        sf::Sprite mySprite;

        static const float SPEED;
};

#endif // SUPERMISSILE_H