#include "Game.hpp"
#include "core/Board.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace minesweeper
{
namespace graphics
{

Game::Game(std::size_t boardSize, unsigned numberOfMines)
  : boardSize_{ boardSize }, numberOfMines_{ numberOfMines }, minesweeperSFML_(boardSize_, numberOfMines_),
    window_(sf::VideoMode(boardSize_ * cellSize_, boardSize_ * cellSize_), "Minesweeper")
{
    mouseListener_.addLeftButtonCallback([this](const core::CellPosition& cell) { minesweeperSFML_.revealCell(cell); });
    mouseListener_.addRightButtonCallback([this](const core::CellPosition& cell) { minesweeperSFML_.markCell(cell); });
    mouseListener_.addMiddleButtonCallback([this]() { minesweeperSFML_.restart(); });
}

void Game::play()
{
    while (window_.isOpen())
    {
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
            }
        }

        mouseListener_.listen(window_);

        window_.clear();
        minesweeperSFML_.draw(window_);
        window_.display();
    }
}

}// namespace graphics
}// namespace minesweeper
