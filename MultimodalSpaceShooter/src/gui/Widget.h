#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "input/MultimodalListener.h"

//////////////////////////////////////////////////
/// Abstract class for every widgets
//////////////////////////////////////////////////
class Widget
{
    public:
        Widget();

        virtual void onEvent(const sf::Event& event);
        virtual void onMultimodalEvent(Multimodal::Event event);
        virtual void update(float frameTime) = 0;
        virtual void draw(sf::RenderTarget& window) const = 0;
};

#endif // WIDGET_H