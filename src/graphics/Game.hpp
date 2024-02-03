#pragma once
#include <SFML/Graphics.hpp>
#include <cstddef>
#include <memory>
#include "TexturesManager.hpp"

namespace minesweeper
{
namespace graphics
{

class Game final
{
public:
    Game(size_t boardSize, unsigned numberOfMines);
    void initGame();
    void gameLoop();

private:
    TexturesManager<MinesweeperTextures> texturesManager_;
    std::unique_ptr<sf::RenderWindow> window_;
    size_t boardSize_;
    unsigned numberOfMines_;
};

}// namespace graphics
}// namespace minesweeper
