#ifndef ISCENE_H
#define ISCENE_H

#include <SFML/Graphics/RenderTarget.hpp>

class IScene
{
    public:
        IScene();
        virtual ~IScene();

        virtual void update(float frameTime) = 0;
        virtual void draw(sf::RenderTarget& window) = 0;
};

#endif // ISCENE_H