#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <set>
#include <SFML/Graphics.hpp>

class GraphicsObject;

class GraphicsEngine
{
    public:
        void addObject(GraphicsObject* object);
        void removeObject(GraphicsObject* object);
        void drawScene(sf::RenderTarget& window);
    
    private:
        GraphicsEngine();
        ~GraphicsEngine();
        
        void updateFpsAverage();

        int                       myFrameCount;
        sf::Clock                 myClock;
        sf::Text                  myFpsText;
        std::set<GraphicsObject*> myObjects;

        friend class Game;
};

#endif // GRAPHICSENGINE_H