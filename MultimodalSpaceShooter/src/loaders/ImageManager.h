#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include "ResourceManager.h"
#include <SFML/Graphics/Image.hpp>

class ImageManager : public ResourceManager<sf::Image>
{
    public:
        virtual std::shared_ptr<sf::Image> load(const std::string& name);
        
    private:
        ImageManager(const std::string& resourcePath = "./");

        friend class Game;
};

/*class Test
{
public:
    Test()  { static int count = 0; i = count++; std::cout << "test ctor " << i << std::endl; }
    ~Test() { std::cout << "test dtor " << i << std::endl; }

    int i;
};

class TestManager : public ResourceManager<Test>
{
    public:
        TestManager(const std::string& resourcePath = "./")
        {
        
        }

        virtual std::shared_ptr<Test> load(const std::string& name)
        {
            std::shared_ptr<Test> test(new Test);
            put(name, test);
            return test;
        }
};*/

#endif // IMAGEMANAGER_H