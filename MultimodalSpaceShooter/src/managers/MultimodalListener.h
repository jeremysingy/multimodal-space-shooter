#ifndef MULTIMODALLISTENER_H
#define MULTIMODALLISTENER_H

#include <SFML/System/Vector2.hpp>
#include "managers/GestureManager.h"

enum MultimodalEvent
{
    VolumeChangedArmUp,
    VolumeChangedArmDown
};

class MultimodalListener
{
    public:
        virtual ~MultimodalListener();

        virtual void onTrackingStateChanged(Tracking::State newState);
        virtual void onMultimodalEvent(MultimodalEvent event);

    protected:
        MultimodalListener();
};

#endif // MULTIMODALLISTENER_H