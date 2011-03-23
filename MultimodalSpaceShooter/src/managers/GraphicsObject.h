#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <SFML/Graphics/RenderTarget.hpp>

class GraphicsObject
{
    public:
        GraphicsObject();
        virtual ~GraphicsObject();

        virtual void draw(sf::RenderTarget& window) const = 0;
};

#endif // GRAPHICSOBJECT_H