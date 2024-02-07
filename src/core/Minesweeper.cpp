#include "Minesweeper.hpp"
#include "MineGenerator.hpp"

namespace minesweeper
{
namespace core
{

Minesweeper::Minesweeper(std::size_t boardSize, unsigned numberOfMines)
  : board_(boardSize), boardSize_(boardSize), numberOfMines_{ numberOfMines }
{
}

void Minesweeper::restart()
{
    gameEnded = false;
    isFirstReveal = true;
    onRestart();
}

void Minesweeper::revealCell(CellPosition cell)
{
    if (isFirstReveal && !gameEnded)
    {
        isFirstReveal = false;
        init(cell);
        return;
    }

    if (gameEnded || board_.isCellRevealed(cell) || board_.isCellFlagged(cell))
    {
        return;
    }

    const State cellState = board_.getCellState(cell);
    if (cellState == State::Mine)
    {
        board_.revealCell(cell);
        gameEnded = true;
        onMineRevealed(cell);
        return;
    }

    board_.revealCell(cell);
    onCellRevealed(cell, StateToNumber(cellState));
    if (board_.isGameWon())
    {
        gameEnded = true;
        onGameWon();
        return;
    }

    if (cellState == State::Empty)
    {
        const auto isCellValid = [this](const CellPosition& cellPos) {
            return cellPos.x_ < boardSize_ && cellPos.y_ < boardSize_;
        };
        for (const auto& neighbor : cellNeighbors)
        {
            const CellPosition cellToReveal(
              cell.x_ + static_cast<std::size_t>(neighbor.first), cell.y_ + static_cast<std::size_t>(neighbor.second));
            if (isCellValid(cellToReveal))
            {
                revealCell(cellToReveal);
            }
        }
    }
}

void Minesweeper::init(CellPosition firstRevealedCell)
{
    MineGenerator mineGenerator(boardSize_);
    board_.initBoard(mineGenerator.generateRandomPositionsWithoutRepetition(firstRevealedCell, numberOfMines_));

    revealCell(firstRevealedCell);
}

void Minesweeper::markCell(CellPosition cell)
{
    if (gameEnded || board_.isCellRevealed(cell))
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
