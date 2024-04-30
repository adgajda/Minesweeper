#pragma once
#include "Board.hpp"
#include "MineGenerator.hpp"
#include <cstddef>
#include <memory>

namespace minesweeper
{
namespace core
{

template<typename MinesweeperImpl>
class MinesweeperCRTP
{
public:
    MinesweeperCRTP(std::size_t boardSize, unsigned numberOfMines)
      : boardSize_{ boardSize }, numberOfMines_{ numberOfMines }
    {
    }

    ~MinesweeperCRTP() = default;
    MinesweeperCRTP(const MinesweeperCRTP&) = delete;
    MinesweeperCRTP& operator=(const MinesweeperCRTP&) = delete;
    MinesweeperCRTP(MinesweeperCRTP&&) = delete;
    MinesweeperCRTP& operator=(MinesweeperCRTP&&) = delete;

    void restart()
    {
        gameEnded = false;
        isFirstReveal = true;
        static_cast<MinesweeperImpl*>(this)->onRestart();
    }

    void revealCell(const CellPosition& cell)
    {
        if (isFirstReveal && !gameEnded)
        {
            isFirstReveal = false;
            revealFirstCell(cell);
            return;
        }

        if (gameEnded || board_->isCellRevealed(cell) || board_->isCellFlagged(cell))
        {
            return;
        }

        const State cellState = board_->getCellState(cell);
        if (cellState == State::Mine)
        {
            board_->revealCell(cell);
            gameEnded = true;
            static_cast<MinesweeperImpl*>(this)->onGameLost(cell);
            return;
        }

        board_->revealCell(cell);
        static_cast<MinesweeperImpl*>(this)->onCellRevealed(cell, StateToNumber(cellState));
        if (board_->isGameWon())
        {
            gameEnded = true;
            static_cast<MinesweeperImpl*>(this)->onGameWon();
            return;
        }

        if (cellState == State::Empty)
        {
            const auto isCellValid = [this](const CellPosition& cellPos) {
                return cellPos.x_ < boardSize_ && cellPos.y_ < boardSize_;
            };
            for (const auto& neighbor : cellNeighbors)
            {
                const CellPosition cellToReveal(cell.x_ + static_cast<std::size_t>(neighbor.first),
                  cell.y_ + static_cast<std::size_t>(neighbor.second));
                if (isCellValid(cellToReveal))
                {
                    revealCell(cellToReveal);
                }
            }
        }
    }

    void markCell(const CellPosition& cell)
    {
        if (gameEnded || board_->isCellRevealed(cell))
        {
            return;
        }

        if (board_->isCellFlagged(cell))
        {
            board_->unflagCell(cell);
            static_cast<MinesweeperImpl*>(this)->onCellFlagRemoved(cell);
        }
        else
        {
            board_->flagCell(cell);
            static_cast<MinesweeperImpl*>(this)->onCellFlagged(cell);
        }
    }

protected:
    std::unique_ptr<Board> board_;

private:
    void revealFirstCell(const CellPosition& firstRevealedCell)
    {
        MineGenerator mineGenerator(boardSize_);
        board_ = std::make_unique<Board>(
          boardSize_, mineGenerator.generateRandomPositionsWithoutRepetition(firstRevealedCell, numberOfMines_));

        revealCell(firstRevealedCell);
    }

    std::size_t boardSize_;
    unsigned numberOfMines_;
    bool gameEnded = false;
    bool isFirstReveal = true;
};

}// namespace core
}// namespace minesweeper
