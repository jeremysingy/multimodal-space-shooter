#ifndef MULTIMODALLISTENER_H
#define MULTIMODALLISTENER_H

#include <SFML/System/Vector2.hpp>
#include "input/GestureManager.h"

namespace Multimodal
{
    enum Event
    {
        VolumeChangedArmUp,
        VolumeChangedArmDown
    };
}

//////////////////////////////////////////////////
/// Base class for an multimoal event listener
//////////////////////////////////////////////////
class MultimodalListener
{
    public:
        virtual ~MultimodalListener();

        virtual void onTrackingStateChanged(Tracking::State newState);
        virtual void onMultimodalEvent(Multimodal::Event event);

    protected:
        MultimodalListener();
};

#endif // MULTIMODALLISTENER_H