#include "managers/MultimodalManager.h"
#include <iostream>

MultimodalManager::MultimodalManager() :
myTrackingState(Tracking::NotInitialized)
{
    myGestureManager.initialize();

    if(sf::SoundRecorder::IsAvailable())
        myVolumeRecorder.Start(11025);
}

MultimodalManager::~MultimodalManager()
{
    myGestureManager.stopTracking();
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

bool MultimodalManager::isMultimodalityAvailable()
{
    return myGestureManager.getState() != Tracking::NotInitialized && sf::SoundRecorder::IsAvailable();
}

void MultimodalManager::startTracking()
{
    myGestureManager.startTracking();
}

Tracking::State MultimodalManager::getTrackingState()
{
    return myGestureManager.getState();
}

void MultimodalManager::update()
{
    // Send notifications of volume changed
    if(myVolumeRecorder.hasLevelIncreased())
    {
        Multimodal::Event event = Multimodal::VolumeChangedArmDown;
        if(myGestureManager.getRightHandPosition().y > myGestureManager.getBodyPosition().y)
            event = Multimodal::VolumeChangedArmUp;
        
        // Send other multimodal event to the listeners
        for(std::set<MultimodalListener*>::iterator i = myListeners.begin(); i != myListeners.end(); ++i)
        {
            (*i)->onMultimodalEvent(event);
        }
    }

    // Send notifications of gesture tracking state changed
    if(myGestureManager.getState() != myTrackingState)
    {
        myTrackingState = myGestureManager.getState();

        // Send event to the listeners
        for(std::set<MultimodalListener*>::iterator i = myListeners.begin(); i != myListeners.end(); ++i)
        {
            (*i)->onTrackingStateChanged(myTrackingState);
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

Volume::Level MultimodalManager::getMicroLevel() const
{
    return myVolumeRecorder.getLevel();
}

