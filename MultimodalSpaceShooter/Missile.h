#ifndef MISSILE_H
#define MISSILE_H

#include "Entity.h"
#include <SFML/Graphics/Shape.hpp>

class Missile : public Entity
{
    public:
        Missile(const sf::Vector2f& initialPos);
        ~Missile();

        virtual void update(float frameTime);
        virtual sf::FloatRect getBoundingRect() const;
        virtual void draw(sf::RenderTarget& window) const;

    private:
        sf::Shape myShape;

        static const float SPEED;
};

#endif // MISSILE_H