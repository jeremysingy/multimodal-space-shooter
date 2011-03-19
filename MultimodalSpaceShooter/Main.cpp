#include <iostream>
#include "Game.h"

#include <SFML/Audio.hpp>

/*class Test
{
public:
    SoundManager sm;
    std::vector<sf::Sound> mySounds;

    void Test::playSound(const std::string& name, float volume)
    {
        std::shared_ptr<sf::SoundBuffer> buffer = sm.get(name);//soundManager().get(name);

        //std::shared_ptr<sf::SoundBuffer> buffer(new sf::SoundBuffer);
        //buffer->LoadFromFile(name);

        sf::Sound sound(*buffer);
        sound.SetVolume(volume);

        mySounds.push_back(sound);
        mySounds.back().Play();

        std::cout << "test" << std::endl;
    }
};*/


//////////////////////////////////////////////////
/// Entry point of the application
//////////////////////////////////////////////////
int main()
{
    try
    {
        // Create and start the game
        Game& game = Game::instance();
        game.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error in game: " << e.what();
    }

    // Update all the objects of the scene
    /*std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    for(std::vector<int>::iterator i = test.begin(); i != test.end(); ++i)
    {
        // Check for collisions
        for(std::vector<int>::iterator j = i + 1; j != test.end(); ++j)
            std::cout << "couple (" << *i << " ; " << *j << ")" << std::endl;

    }*/

    //Test test;
    //test.playSound("sounds/boum.wav", 100.f);

    return EXIT_SUCCESS;
}