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
        
        void drawFps(sf::RenderTarget& window);
        void drawVolumeIndicator(sf::RenderTarget& window);

        int                       myFrameCount;
        sf::Clock                 myClock;
        sf::Text                  myFpsText;
        std::set<GraphicsObject*> myObjects;

        sf::Shape myVolumeViewer;
        sf::Shape myVolumeOutline;

        friend class Game;
};

#endif // GRAPHICSENGINE_H