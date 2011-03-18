#ifndef MISSILE_H
#define MISSILE_H

#include "Entity.h"
#include <SFML/Graphics/Shape.hpp>

class Missile : public Entity
{
    public:
        Missile(const sf::Vector2f& initialPos);
        virtual ~Missile();

        virtual void update(float frameTime);
        virtual void draw(sf::RenderTarget& window) const;
        virtual void onCollision(const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const;

    private:
        sf::Shape myShape;


        static const float SPEED;
};

#endif // MISSILE_H