#include "PhysicsObject.h"
#include "Managers.h"

PhysicsObject::PhysicsObject()
{
    physicsEngine().addObject(this);
}


PhysicsObject::~PhysicsObject()
{
    physicsEngine().removeObject(this);
}

void PhysicsObject::onCollision(const sf::FloatRect& area)
{
    
}
