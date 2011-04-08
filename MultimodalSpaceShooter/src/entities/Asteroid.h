#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Asteroid : public Entity
{
    public:
        Asteroid(const sf::Image& image, const sf::Vector2f& position, const float initialSpeed = 10.f);
        virtual ~Asteroid();

        virtual void update(float frameTime);
        virtual void onCollision(Object::Type otherType, const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Sprite mySprite;
        float mySpeed;
};

#endif // ASTEROID_H