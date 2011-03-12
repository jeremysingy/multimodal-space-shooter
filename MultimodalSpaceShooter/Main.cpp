#include <iostream>
#include "Game.h"

//////////////////////////////////////////////////
/// Entry point of the application
//////////////////////////////////////////////////
int main()
{
    // Create and start the game
    Game& game = Game::instance();
    game.run();

    return EXIT_SUCCESS;
}