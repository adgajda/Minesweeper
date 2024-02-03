#include "Game.hpp"

namespace minesweeper
{
namespace graphics
{

Game::Game(size_t boardSize, unsigned numberOfMines)
  : texturesManager_("../textures/"), boardSize_{ boardSize }, numberOfMines_{ numberOfMines }
// TODO: PATH should not be hardcoded
{
}

void Game::initGame()
{
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_0.png", MinesweeperTextures::Empty);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_1.png", MinesweeperTextures::One);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_2.png", MinesweeperTextures::Two);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_3.png", MinesweeperTextures::Three);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_4.png", MinesweeperTextures::Four);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_5.png", MinesweeperTextures::Five);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_6.png", MinesweeperTextures::Six);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_7.png", MinesweeperTextures::Seven);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_8.png", MinesweeperTextures::Eight);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_mine_hit.png", MinesweeperTextures::MineHit);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_mine.png", MinesweeperTextures::Mine);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_flag.png", MinesweeperTextures::Flag);
    texturesManager_.loadTexture("Minesweeper_LAZARUS_21x21_unexplored.png", MinesweeperTextures::Covered);
    const unsigned cellSize{ 21 };
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
        window_->display();
    }
}

}// namespace graphics
}// namespace minesweeper
