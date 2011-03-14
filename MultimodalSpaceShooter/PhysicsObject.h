#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML/Graphics/Rect.hpp>

class PhysicsObject
{
    public:
        PhysicsObject();
        virtual ~PhysicsObject();

        virtual void update(float frameTime) = 0;
        virtual void onCollision(const sf::FloatRect& area);
        virtual sf::FloatRect getBoundingRect() const = 0;
};

#endif // PHYSICSOBJECT_H