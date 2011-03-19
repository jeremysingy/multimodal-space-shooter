#include "MultimodalManager.h"

MultimodalManager::MultimodalManager()
{

}


MultimodalManager::~MultimodalManager()
{

}

void MultimodalManager::addListener(MultimodalListener* listener) 
{
    if(listener)
        myListeners.insert(listener);
}

void MultimodalManager::removeListener(MultimodalListener* listener) 
{
    myListeners.erase(listener);
}

void MultimodalManager::update()
{
    // TODO
}

const sf::Vector2f& MultimodalManager::getBodyPosition() const
{
    return myGestureManager.getBodyPosition();
}

const sf::Vector2f& MultimodalManager::getLeftHandPosition() const
{
    return myGestureManager.getLeftHandPosition();
}

const sf::Vector2f& MultimodalManager::getRightHandPosition() const
{
    return myGestureManager.getRightHandPosition();
}
