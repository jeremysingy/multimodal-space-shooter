#ifndef PLANET_H
#define PLANET_H

#include "Entity.h"
#include <SFML/System/Vector2.hpp>

class Planet : public Entity
{
    public:
        Planet(const sf::Vector2f& position);
        virtual ~Planet();

        virtual void update(float frameTime);
        virtual void onCollision(const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Shape mySprite;
};

#endif // PLANET_H