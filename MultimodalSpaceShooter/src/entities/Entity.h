#ifndef ENTITY_H
#define ENTITY_H

#include "managers/GraphicsObject.h"
#include "managers/PhysicsObject.h"
#include <SFML/Graphics/Shape.hpp>

class Entity : public GraphicsObject,
               public PhysicsObject
{
    public:
        Entity();
        virtual ~Entity();

        void destroy();
        bool isDestroyed() const;

    private:
        Entity(const Entity&);
        Entity& operator =(const Entity&);

        bool myIsDestroyed;
};

#endif // ENTITY_H