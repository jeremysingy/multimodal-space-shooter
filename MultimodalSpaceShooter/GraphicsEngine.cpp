#include "GraphicsEngine.h"
#include "GraphicsObject.h"
#include "Spaceship.h"
#include "Planet.h"

#include <sstream>
#include <iomanip>

GraphicsEngine::GraphicsEngine() :
myFrameCount(0),
myFpsText("", sf::Font::GetDefaultFont(), 16)
{

}


GraphicsEngine::~GraphicsEngine()
{

}

void GraphicsEngine::addObject(GraphicsObject* object)
{
    myObjects.insert(object);
}

void GraphicsEngine::removeObject(GraphicsObject* object)
{
    myObjects.erase(object);
}

void GraphicsEngine::drawScene(sf::RenderTarget& window)
{
    // Draw all the objects of the scene
    for(std::set<GraphicsObject*>::iterator i = myObjects.begin(); i != myObjects.end(); ++i)
    {
        (*i)->draw(window);
    }

    // Print current fps
    updateFpsAverage();
    window.Draw(myFpsText);
}

void GraphicsEngine::updateFpsAverage()
{
    float crtTime = myClock.GetElapsedTime();

    if(crtTime >= 1.f)
    {
        float fpsAvg = myFrameCount / crtTime;

        std::ostringstream oss;
        oss << "fps: " << std::setprecision(0) << std::fixed << fpsAvg;
        myFpsText.SetString(oss.str());

        myFrameCount = 0;
        myClock.Reset();
    }

    ++myFrameCount;
}
