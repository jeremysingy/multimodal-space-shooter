#ifndef SUPERMISSILE_H
#define SUPERMISSILE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

enum direction{
    left,
    right,
    straight
};

class SuperMissile : public Entity
{
    public:
        SuperMissile(const sf::Vector2f& initialPos, direction direct,float angle);
        virtual ~SuperMissile();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;
        virtual void onCollision(const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;

    private:
        float myAngle;
        sf::Sprite mySprite;
        direction myDirection;

        static const float SPEED;
};

#endif // SUPERMISSILE_H