#include "Entity.h"

Entity::Entity()
: myIsDestroyed(false)
{
    
}


Entity::~Entity()
{
    
}

void Entity::destroy()
{
    myIsDestroyed = true;
}

bool Entity::isDestroyed() const
{
    return myIsDestroyed;
}