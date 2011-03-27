#include "managers/MultimodalManager.h"

MultimodalManager::MultimodalManager()
{
    if(sf::SoundRecorder::IsAvailable())
    {
        myVolumeRecorder.Start(11025);
    }

    myGestureManager.initialize();
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

bool MultimodalManager::isGestureEnabled()
{
    return myGestureManager.isInitialized();
}

void MultimodalManager::update()
{
    myGestureManager.update();

    if(myVolumeRecorder.hasVaried())
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

