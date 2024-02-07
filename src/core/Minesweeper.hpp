#pragma once
#include "Board.hpp"
#include <cstddef>
#include <memory>

namespace minesweeper
{
namespace core
{

class Minesweeper
{
public:
    Minesweeper(std::size_t boardSize, unsigned numberOfMines);

    Minesweeper(const Minesweeper&) = delete;
    Minesweeper& operator=(const Minesweeper&) = delete;

    Minesweeper(Minesweeper&&) = delete;
    Minesweeper& operator=(Minesweeper&&) = delete;

    void restart();
    void revealCell(const CellPosition& cell);
    void markCell(const CellPosition& cell);

protected:
    virtual void onGameLost(const CellPosition& cell) = 0;
    virtual void onCellRevealed(const CellPosition& cell, unsigned minesAround) = 0;
    virtual void onCellFlagged(const CellPosition& cell) = 0;
    virtual void onCellFlagRemoved(const CellPosition& cell) = 0;
    virtual void onRestart() = 0;
    virtual void onGameWon() = 0;
    ~Minesweeper() = default;

    std::unique_ptr<Board> board_;

private:
    void revealFirstCell(const CellPosition& firstRevealedCell);

    std::size_t boardSize_;
    unsigned numberOfMines_;
    bool gameEnded = false;
    bool isFirstReveal = true;
};

}// namespace core
}// namespace minesweeper
