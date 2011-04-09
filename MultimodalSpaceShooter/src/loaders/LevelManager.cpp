#include "loaders/LevelManager.h"
#include "entities/Planet.h"
#include "entities/Asteroid.h"
#include "core/Managers.h"
#include <utils/tinyxml/tinyxml.h>

LevelManager::LevelManager()
{

}

void LevelManager::load(const std::string& name)
{
    while(!myEntityModels.empty())
        myEntityModels.pop();

    TiXmlDocument document(name.c_str());

    if(!document.LoadFile())
        throw std::invalid_argument(name + ": couldn't load XML world: " + document.ErrorDesc());

    // Get background element
    TiXmlHandle handle(&document);
    TiXmlElement* bgElement = handle.FirstChildElement().FirstChildElement("background").ToElement();

    float speed;
    bgElement->QueryFloatAttribute("speed", &speed);

    myBackground = std::shared_ptr<Background>(new Background(*imageManager().get(bgElement->Attribute("image")), speed));

    // Get enemy element (planet or asteroid)
    TiXmlElement* element = handle.FirstChildElement().FirstChildElement("enemies").FirstChild().ToElement();
    
    // Get all elements in the file and add it to the priority queue
    while(element)
    {
        float coordinate = 0, speed = 0, angle = 0, rotation = 0, time = 0;

        element->QueryFloatAttribute("xCoordinate", &coordinate);
        element->QueryFloatAttribute("speed", &speed);
        element->QueryFloatAttribute("angle", &angle);
        element->QueryFloatAttribute("time", &time);

        if(element->Attribute("rotationSpeed"))
            element->QueryFloatAttribute("rotationSpeed", &rotation);

        // Load the image in memory if it is still not loaded
        imageManager().get(element->Attribute("image"));

        // Add the entity to the priority queue
        myEntityModels.push(EntityModel(element->Value(), element->Attribute("image"), coordinate, speed, angle, rotation, time));

        element = element->NextSiblingElement();
    }
}

std::shared_ptr<Background> LevelManager::getBackground()
{
    return myBackground;
}

std::shared_ptr<Entity> LevelManager::getNextEntity(float gameTime)
{
    if(!myEntityModels.empty())
    {
        EntityModel entityModel = myEntityModels.top();

        if(entityModel.getTime() <= gameTime)
        {
            myEntityModels.pop();
			sf::Image& image = *imageManager().get(entityModel.getImageFile());
				
            float initialPos = -static_cast<float>(image.GetHeight());

            std::shared_ptr<Entity> ptrEntity;

			if(entityModel.getType() == "planet")
				ptrEntity = std::shared_ptr<Entity>(new Planet(image, sf::Vector2f(entityModel.getXCoordinate(), initialPos), entityModel.getSpeed()));
            else if(entityModel.getType() == "asteroid")
                ptrEntity = std::shared_ptr<Entity>(new Asteroid(image, sf::Vector2f(entityModel.getXCoordinate(), initialPos), entityModel.getSpeed(),
                                                    entityModel.getAngle(), entityModel.getRotation()));

            return ptrEntity;
        }
    }

    // No entity for now, return a null pointer
    return std::shared_ptr<Entity>();
}

bool LevelManager::isWorldEnded()
{
    return myEntityModels.empty();
}
