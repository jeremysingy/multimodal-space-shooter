#ifndef ENTITY_H
#define ENTITY_H

#include "GraphicsObject.h"
#include "PhysicsObject.h"
#include <SFML/Graphics/Shape.hpp>

class Entity : public GraphicsObject,
               public PhysicsObject
{
    public:
        Entity();
        virtual ~Entity();

        void destroy();
        bool isDestroyed() const;

        bool myIsDestroyed;
};

#endif // ENTITY_H