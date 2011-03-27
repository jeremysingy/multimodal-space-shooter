#ifndef MULTIMODALLISTENER_H
#define MULTIMODALLISTENER_H

#include <SFML/System/Vector2.hpp>

enum MultimodalEvent
{
    VolumeChangedArmUp,
    VolumeChangedArmDown
};

class MultimodalListener
{
    public:
        virtual ~MultimodalListener();

        virtual void onMultimodalEvent(MultimodalEvent event);

    protected:
        MultimodalListener();
};

#endif // MULTIMODALLISTENER_H