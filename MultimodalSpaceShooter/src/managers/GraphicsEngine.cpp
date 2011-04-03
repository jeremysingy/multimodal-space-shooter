#include "managers/GraphicsEngine.h"
#include "managers/GraphicsObject.h"
#include "entities/Spaceship.h"
#include "entities/Planet.h"
#include "managers/Managers.h"

#include <sstream>
#include <iomanip>

GraphicsEngine::GraphicsEngine() :
myFrameCount(0),
myFpsText("", sf::Font::GetDefaultFont(), 16)
{
    myVolumeViewer = sf::Shape::Rectangle(sf::FloatRect(0, 0, 1, 5), sf::Color::Red);
    myVolumeViewer.SetPosition(680, 5);

    myVolumeOutline = sf::Shape::Rectangle(sf::FloatRect(0, 0, 100, 5), sf::Color(0, 0, 0, 0), 1.f, sf::Color::Red);
    myVolumeOutline.SetPosition(680, 5);

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

    // Draw the background


    // Draw all the objects of the scene
    for(std::set<GraphicsObject*>::iterator i = myObjects.begin(); i != myObjects.end(); ++i)
    {
        (*i)->draw(window);
    }

    // Print current fps and volume indicator
    drawFps(window);
    drawVolumeIndicator(window);
}

void GraphicsEngine::drawFps(sf::RenderTarget& window)
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

    window.Draw(myFpsText);
}

void GraphicsEngine::drawVolumeIndicator(sf::RenderTarget& window)
{
    float volume = multimodalManager().getMicroVolume();
    if(volume > 100.f)
        volume = 100.f;

    myVolumeViewer.SetScaleX(volume);

    window.Draw(myVolumeOutline);
    window.Draw(myVolumeViewer);
}
