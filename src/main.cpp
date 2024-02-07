#include "graphics/Game.hpp"

int main()
{
    minesweeper::graphics::Game game(21, 80);
    game.gameLoop();
    return 0;
}