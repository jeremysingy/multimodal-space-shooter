#include "ImageManager.h"

ImageManager::ImageManager(const std::string& resourcePath) :
ResourceManager(resourcePath)
{

}

std::shared_ptr<sf::Image> ImageManager::load(const std::string& name)
{
    std::shared_ptr<sf::Image> imagePtr(new sf::Image);

    if(!imagePtr->LoadFromFile(myPath + name))
        throw std::invalid_argument(name + ": couldn't load image");

    put(name, imagePtr);

    return imagePtr;
}
