#include <iostream>
#include "Game.h"

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

    return EXIT_SUCCESS;
}