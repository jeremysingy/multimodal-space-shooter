#include "PhysicsEngine.h"
#include "PhysicsObject.h"

PhysicsEngine::PhysicsEngine()
{

}


PhysicsEngine::~PhysicsEngine()
{

}

void PhysicsEngine::addObject(PhysicsObject* object)
{
    myObjects.insert(object);
}

void PhysicsEngine::removeObject(PhysicsObject* object)
{
    myObjects.erase(object);
}

void PhysicsEngine::updateScene(float frameTime)
{
    // Update all the objects of the scene
    for(std::set<PhysicsObject*>::iterator i = myObjects.begin(); i != myObjects.end(); ++i)
    {
        (*i)->update(frameTime);
    }
}
