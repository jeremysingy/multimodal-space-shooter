#ifndef MULTIMODALMANAGER_H
#define MULTIMODALMANAGER_H

#include <set>
#include <SFML/System/Vector2.hpp>

#include "GestureManager.h"
#include "VolumeRecorder.h"

class MultimodalListener;

class MultimodalManager
{
    public:
        void addListener(MultimodalListener* listener);
        void removeListener(MultimodalListener* listener);
        MultimodalManager();
        ~MultimodalManager();
        
        void update();
        const sf::Vector2f& getBodyPosition() const;
        const sf::Vector2f& getLeftHandPosition() const;
        const sf::Vector2f& getRightHandPosition() const;

    private:
        std::set<MultimodalListener*> myListeners;

        GestureManager myGestureManager;
        VolumeRecorder myVolumeRecorder;

        friend class Game;
};

#endif // MULTIMODALMANAGER_H