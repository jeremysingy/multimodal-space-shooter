#include "managers/MultimodalManager.h"
#include <iostream>

MultimodalManager::MultimodalManager()
{
    
    if(sf::SoundRecorder::IsAvailable())
        myVolumeRecorder.Start(11025);
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

bool MultimodalManager::enableGesture()
{
    myGestureManager.initialize();
    myGestureManager.startTracking();

    return myGestureManager.isInitialized();
}

bool MultimodalManager::isGestureEnabled()
{
    return myGestureManager.isInitialized();
}

void MultimodalManager::update()
{
    if(myVolumeRecorder.hasLevelIncreased())
    {
        MultimodalEvent event = VolumeChangedArmDown;
        if(myGestureManager.getRightHandPosition().y > myGestureManager.getBodyPosition().y)
            event = VolumeChangedArmUp;
        
        // Send other multimodal event to the listeners
        for(std::set<MultimodalListener*>::iterator i = myListeners.begin(); i != myListeners.end(); ++i)
        {
            (*i)->onMultimodalEvent(event);
        }
    }
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

