#include "MinesweeperSFML.hpp"

namespace minesweeper
{
namespace graphics
{

MinesweeperSFML::MinesweeperSFML(size_t boardSize, unsigned numberOfMines)
  : Minesweeper(boardSize, numberOfMines), texturesManager_("../textures/")// TODO: PATH should not be hardcoded
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

    cellSprites_.resize(boardSize);
    for (auto& row : cellSprites_)
    {
        row.resize(boardSize);
    }

    for (size_t i = 0; i < boardSize; ++i)
    {
        for (size_t j = 0; j < boardSize; ++j)
        {
            cellSprites_[i][j].setTexture(texturesManager_.getTexture(MinesweeperTextures::Covered));
            const float cellSize{ 21.f };
            cellSprites_[i][j].setPosition(i * cellSize, j * cellSize);
        }
    }
}

void MinesweeperSFML::draw(sf::RenderWindow& window)
{
    for (const auto& row : cellSprites_)
    {
        for (const auto& sprite : row)
        {
            window.draw(sprite);
        }
    }
}

void MinesweeperSFML::onMineRevealed(const core::CellPosition&)
{
}

void MinesweeperSFML::onCellRevealed(const core::CellPosition&, unsigned)
{
}

void MinesweeperSFML::onCellFlagged(const core::CellPosition&)
{
}

void MinesweeperSFML::onCellFlagRemoved(const core::CellPosition&)
{
}

}// namespace graphics
}// namespace minesweeper
