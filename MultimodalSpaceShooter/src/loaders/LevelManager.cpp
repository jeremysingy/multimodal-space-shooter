#include "loaders/LevelManager.h"
#include "entities/Planet.h"
#include "managers/Managers.h"
#include <utils/tinyxml/tinyxml.h>
#include <sstream>

LevelManager::LevelManager()
{

}

int LevelManager::load(const std::string& name)
{
    TiXmlDocument doc(name.c_str());

    if(!doc.LoadFile())
    {
        std::cerr << "Error while loading world" << std::endl;
        std::cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << std::endl;
        return 1;
    }

    // Temp variables
    float coordinate;
    float speed;
    float time;

    // Get first node
    TiXmlHandle hdl(&doc);
    TiXmlElement* element = hdl.FirstChild("world").FirstChild("enemies").FirstChild("enemy").ToElement();

    // Get all elements in the file and add it to the priority queue
    while(element)
    {
        std::istringstream issCoordinate(element->Attribute("xCoordinate"));
        issCoordinate >> coordinate;

        std::istringstream issSpeed(element->Attribute("speed"));
        issSpeed >> speed;
        
        std::istringstream issTime(element->Attribute("time"));
        issTime >> time;

        // Load the image in memory if it is still not loaded
        imageManager().get(element->Attribute("image"));

        // Add the entity to the priority queue
        myEntityModels.push(EntityModel(element->Attribute("type"), element->Attribute("image"), coordinate, speed, time));

        element = element->NextSiblingElement();
    }

    return 0;
}

std::shared_ptr<Entity> LevelManager::getNextEntity(float gameTime)
{
    if(!myEntityModels.empty())
    {
        EntityModel entityModel = myEntityModels.top();

        if(entityModel.getTime() <= gameTime)
        {
            myEntityModels.pop();
            std::shared_ptr<Entity> planet(new Planet(sf::Vector2f(entityModel.getXCoordinate(), -70.f), entityModel.getSpeed()));

            return planet;
        }
    }

    // No entity for now, return a null pointer
    return std::shared_ptr<Entity>();
}

bool LevelManager::isWorldEnded()
{
    return myEntityModels.empty();
}
