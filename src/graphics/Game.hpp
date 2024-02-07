#pragma once
#include "MinesweeperSFML.hpp"
#include "MouseListener.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstddef>
#include <memory>

namespace minesweeper
{
namespace graphics
{

class Game final
{
public:
    Game(std::size_t boardSize, unsigned numberOfMines);
    void initGame();
    void gameLoop();

private:
    std::unique_ptr<MinesweeperSFML> minesweeperSFML_;
    std::unique_ptr<sf::RenderWindow> window_;
    std::unique_ptr<MouseListener> mouseListener_;
    std::size_t boardSize_;
    unsigned numberOfMines_;
};

}// namespace graphics
}// namespace minesweeper
