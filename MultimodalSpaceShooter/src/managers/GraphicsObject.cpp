#include "managers/GraphicsObject.h"
#include "managers/Managers.h"

GraphicsObject::GraphicsObject()
{
    graphicsEngine().addObject(this);
}


GraphicsObject::~GraphicsObject()
{
    graphicsEngine().removeObject(this);
}
