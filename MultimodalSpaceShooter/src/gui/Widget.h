#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "managers/MultimodalListener.h"

class Widget
{
    public:
        Widget();
        virtual ~Widget();

        virtual void onEvent(const sf::Event& event) { };
        virtual void onMultimodalEvent(Multimodal::Event event) { };
        virtual void update(float frameTime) = 0;
        virtual void draw(sf::RenderTarget& window) const = 0;

    protected:
        //Widget(const Widget&);
        //Widget& operator =(const Widget&);
};

#endif // WIDGET_H