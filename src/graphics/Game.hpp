#pragma once
#include "MinesweeperSFML.hpp"
#include "MouseListener.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstddef>

namespace minesweeper
{
namespace graphics
{

class Game final
{
public:
    Game(std::size_t boardSize, unsigned numberOfMines);
    void gameLoop();

private:
    static constexpr unsigned cellSize{ 21 };
    std::size_t boardSize_;
    unsigned numberOfMines_;
    MinesweeperSFML minesweeperSFML_;
    MouseListener mouseListener_;
    sf::RenderWindow window_;
};

}// namespace graphics
}// namespace minesweeper
