#include "Entity.h"

Entity::Entity(Type type) :
myType(type),
myIsDestroyed(false)
{
    
}


Entity::~Entity()
{
    
}

void Entity::onCollision(Type otherType, const sf::FloatRect& area)
{

}

Entity::Type Entity::getType() const
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