#include "PlayableEntity.h"

const int PlayableEntity::MAX_LIFE = 5;

PlayableEntity::PlayableEntity() :
Entity(Object::PLAYER),
myLife(MAX_LIFE)
{

}

unsigned int PlayableEntity::getLife()
{
    return myLife;
}
