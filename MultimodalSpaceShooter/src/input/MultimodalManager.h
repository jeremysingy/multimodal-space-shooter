#ifndef MULTIMODALMANAGER_H
#define MULTIMODALMANAGER_H

#include <set>
#include <SFML/System/Vector2.hpp>

#include "input/GestureManager.h"
#include "input/VolumeRecorder.h"
#include "input/MultimodalListener.h"

//////////////////////////////////////////////////
/// Manage the multimodal events like the gestures
/// and the voice input, using other managers
///
/// Make the eventual fusion to combine theses
/// modalities
//////////////////////////////////////////////////
class MultimodalManager
{
    public:
        void addListener(MultimodalListener* listener);
        void removeListener(MultimodalListener* listener);
        MultimodalManager();
        ~MultimodalManager();
        
        bool isMultimodalityAvailable();
        void startTracking();
        Tracking::State getTrackingState();
        bool hasStateChanged();
        void update();

        const sf::Vector2f& getBodyPosition() const;
        const sf::Vector2f& getLeftHandPosition() const;
        const sf::Vector2f& getRightHandPosition() const;
        float getMicroVolume() const;
        Volume::Level getMicroLevel() const;

    private:
        std::set<MultimodalListener*> myListeners;

        GestureManager myGestureManager;
        VolumeRecorder myVolumeRecorder;

        Tracking::State myTrackingState;

        friend class Game;
};

#endif // MULTIMODALMANAGER_H