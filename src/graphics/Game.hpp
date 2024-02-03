#pragma once
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <memory>

namespace minesweeper
{
namespace graphics
{

class Game
{
public:
    Game(size_t boardSize, unsigned numberOfMines);
    void initGame();
    void gameLoop();

private:
    std::unique_ptr<sf::RenderWindow> window_;
    size_t boardSize_;
    unsigned numberOfMines_;
};

}// namespace graphics
}// namespace minesweeper
