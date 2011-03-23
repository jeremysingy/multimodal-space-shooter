#ifndef MULTIMODALLISTENER_H
#define MULTIMODALLISTENER_H

#include <SFML/System/Vector2.hpp>

class MultimodalListener
{
    public:
        virtual ~MultimodalListener();

        enum GestureType
        {
            GestureDown,
            GestureUp
        };

        //virtual void onVolumeChanged(const sf::Event& event);
        virtual void onMultimodalEvent(GestureType gestureType);

    protected:
        MultimodalListener();
};

#endif // MULTIMODALLISTENER_H