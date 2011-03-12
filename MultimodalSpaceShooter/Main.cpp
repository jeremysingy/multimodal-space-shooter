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
    catch(std::exception& e)
    {
        std::cerr << "Error in game: " << e.what();
    }

    return EXIT_SUCCESS;
}