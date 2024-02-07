#include "Game.hpp"
#include "core/Board.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace minesweeper
{
namespace graphics
{

Game::Game(std::size_t boardSize, unsigned numberOfMines) : boardSize_{ boardSize }, numberOfMines_{ numberOfMines }
{
}

void Game::initGame()
{
    const unsigned cellSize{ 21 };
    minesweeperSFML_ = std::make_unique<MinesweeperSFML>(boardSize_, numberOfMines_);
    mouseListener_ = std::make_unique<MouseListener>();
    mouseListener_->addLeftButtonCallback([this](core::CellPosition cell) { minesweeperSFML_->revealCell(cell); });
    mouseListener_->addRightButtonCallback([this](core::CellPosition cell) { minesweeperSFML_->markCell(cell); });
    mouseListener_->addMiddleButtonCallback([this]() { minesweeperSFML_->restart(); });

    window_ =
      std::make_unique<sf::RenderWindow>(sf::VideoMode(boardSize_ * cellSize, boardSize_ * cellSize), "Minesweeper");
}

void Game::gameLoop()
{
    while (window_->isOpen())
    {
        sf::Event event;
        while (window_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_->close();
        }

        mouseListener_->listen(*window_);

        window_->clear();
        minesweeperSFML_->draw(*window_);
        window_->display();
    }
}

}// namespace graphics
}// namespace minesweeper
