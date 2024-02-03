#include "Game.hpp"

namespace minesweeper
{
namespace graphics
{

Game::Game(size_t boardSize, unsigned numberOfMines) : boardSize_{ boardSize }, numberOfMines_{ numberOfMines }
{
}

void Game::initGame()
{
    const unsigned cellSize{ 21 };
    minesweeperSFML_ = std::make_unique<MinesweeperSFML>(boardSize_, numberOfMines_);
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

        window_->clear();
        minesweeperSFML_->draw(*window_);
        window_->display();
    }
}

}// namespace graphics
}// namespace minesweeper
