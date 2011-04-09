#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

//////////////////////////////////////////////////
/// Asteroid in the space that can destroy the spacehip
//////////////////////////////////////////////////
class Asteroid : public Entity
{
    public:
        Asteroid(const sf::Image& image, const sf::Vector2f& position, float initialSpeed, float angle, float rotationSpeed);

        virtual void update(float frameTime);
        virtual void onCollision(Object::Type otherType, const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Sprite mySprite;

        float mySpeed;
        float myAngle;
        float myRotationSpeed;
};

#endif // ASTEROID_H