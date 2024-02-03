#include "MinesweeperSFML.hpp"

namespace minesweeper
{
namespace graphics
{

MinesweeperSFML::MinesweeperSFML() : Minesweeper(2, 2)
{
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
