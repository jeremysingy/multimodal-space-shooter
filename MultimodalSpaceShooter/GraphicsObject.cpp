#include "GraphicsObject.h"
#include "Managers.h"

GraphicsObject::GraphicsObject()
{
    graphicsEngine().addObject(this);
}


GraphicsObject::~GraphicsObject()
{
    graphicsEngine().removeObject(this);
}
