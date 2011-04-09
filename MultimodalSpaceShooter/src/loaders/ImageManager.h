#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "ResourceManager.h"
#include <SFML/Graphics/Image.hpp>

//////////////////////////////////////////////////
/// Image manager
/// Manages the life cycle of these image ressources
//////////////////////////////////////////////////
class ImageManager : public ResourceManager<sf::Image>
{
    public:
        virtual std::shared_ptr<sf::Image> load(const std::string& name);
        
    private:
        ImageManager(const std::string& resourcePath = "./");

        friend class Game;
};

#endif // IMAGEMANAGER_H