#include "Entity.h"

Entity::Entity(Object::Type type) :
myType(type),
myIsDestroyed(false)
{
    
}


Entity::~Entity()
{
    
}

void Entity::onCollision(Object::Type otherType, const sf::FloatRect& area)
{

}

Object::Type Entity::getType() const
{
    return myType;
}

void Entity::destroy()
{
    myIsDestroyed = true;
}

bool Entity::isDestroyed() const
{
    return myIsDestroyed;
}