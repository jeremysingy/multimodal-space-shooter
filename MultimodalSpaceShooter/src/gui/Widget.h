#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Widget
{
    public:
        Widget();
        virtual ~Widget();

        virtual void onEvent(const sf::Event& event) { };
        virtual void draw(sf::RenderTarget& window) const = 0;

    private:
        Widget(const Widget&);
        Widget& operator =(const Widget&);
};

#endif // WIDGET_H