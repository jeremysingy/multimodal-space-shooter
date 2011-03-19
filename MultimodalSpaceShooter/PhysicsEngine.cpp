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
    //typedef std::vector<PhysicsObject*>::iterator it;
    typedef std::set<PhysicsObject*>::iterator it;

    // Update all the objects of the scene
    for(it i = myObjects.begin(); i != myObjects.end(); ++i)
    {
        (*i)->update(frameTime);
    }

    // Check for possible collisions
    manageCollisions();
}

void PhysicsEngine::manageCollisions()
{
    typedef std::set<PhysicsObject*>::iterator it;

    for(it i = myObjects.begin(); i != myObjects.end(); ++i)
    {
        for(it j = myObjects.begin(); j != myObjects.end(); ++j)
        {
            if(*i != *j)
            {
                sf::FloatRect collisionArea;

                // TODO: handle a better way...
                if(isCollide(*i, *j, collisionArea))
                    (*i)->onCollision(collisionArea);
            }
        }
    }
}

bool PhysicsEngine::isCollide(const PhysicsObject* object1, const PhysicsObject* object2, sf::FloatRect& collisionArea)
{
    return object1->getBoundingRect().Intersects(object2->getBoundingRect(), collisionArea);
}
