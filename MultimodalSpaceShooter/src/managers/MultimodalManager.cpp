#include "managers/MultimodalManager.h"

MultimodalManager::MultimodalManager()
{
    if(sf::SoundRecorder::IsAvailable())
    {
        myVolumeRecorder.Start(11025);
    }
}


MultimodalManager::~MultimodalManager()
{
    myVolumeRecorder.Stop();
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
    //myGestureManager.update();
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

float MultimodalManager::getMicroVolume() const
{
    return myVolumeRecorder.getVolume();
}

