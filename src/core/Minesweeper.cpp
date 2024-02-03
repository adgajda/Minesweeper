#include "Minesweeper.hpp"
#include "MineGenerator.hpp"

namespace minesweeper
{
namespace core
{

Minesweeper::Minesweeper(size_t boardSize, unsigned numberOfMines)
  : board_(boardSize), boardSize_(boardSize), numberOfMines_{ numberOfMines }
{
}

void Minesweeper::initGame(CellPosition firstRevealedCell)
{
    MineGenerator mineGenerator(boardSize_);
    board_.initBoard(mineGenerator.generateRandomPositionsWithoutRepetition(firstRevealedCell, numberOfMines_));

    revealCell(firstRevealedCell);
}

void Minesweeper::revealCell(CellPosition cell)
{
    if (board_.isCellRevealed(cell) || board_.isCellFlagged(cell))
    {
        return;
    }

    const State cellState = board_.getCellState(cell);
    if (cellState == State::Mine)
    {
        board_.revealCell(cell);
        onMineRevealed(cell);
        return;
    }

    if (cellState == State::Empty)
    {
        board_.revealCell(cell);
        onCellRevealed(cell, 0);

        const auto isCellValid = [this](const CellPosition& cellPos) {
            return cellPos.x_ < boardSize_ && cellPos.y_ < boardSize_;
        };
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_ - 1, cell.y_ });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_ - 1, cell.y_ - 1 });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_ - 1, cell.y_ + 1 });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_, cell.y_ - 1 });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_, cell.y_ + 1 });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_ + 1, cell.y_ });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_ - 1, cell.y_ - 1 });
        }
        if (const CellPosition cellToReveal(cell.x_ - 1, cell.y_); isCellValid(cellToReveal))
        {
            revealCell({ cell.x_ - 1, cell.y_ + 1 });
        }

        return;
    }

    board_.revealCell(cell);
    onCellRevealed(cell, StateToNumber(cellState));
}

void Minesweeper::markCell(CellPosition cell)
{
    if (board_.isCellRevealed(cell))
    {
        return;
    }

    if (board_.isCellFlagged(cell))
    {
        board_.unflagCell(cell);
        onCellFlagRemoved(cell);
    }
    else
    {
        board_.flagCell(cell);
        onCellFlagged(cell);
    }
}

}// namespace core
}// namespace minesweeper
