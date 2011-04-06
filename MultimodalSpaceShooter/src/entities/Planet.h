#ifndef PLANET_H
#define PLANET_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Planet : public Entity
{
    public:
        Planet(const sf::Image& image, const sf::Vector2f& position, const float initialSpeed = 10.f);
        virtual ~Planet();

        virtual void update(float frameTime);
        virtual void onCollision(Type otherType, const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Sprite mySprite;
        float mySpeed;
};

#endif // PLANET_H