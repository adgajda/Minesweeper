#include "graphics/Game.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    minesweeper::graphics::Game game(21, 100);
    game.initGame();
    game.gameLoop();
    return 0;
}