#include <iostream>
#include "core/Game.h"
#include <algorithm>

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
        std::cerr << "Error in game: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
