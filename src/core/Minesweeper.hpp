#pragma once
#include "Board.hpp"

namespace minesweeper
{
namespace core
{

class Minesweeper
{
public:
    Minesweeper(size_t boardSize, unsigned numberOfMines);

    Minesweeper(const Minesweeper&) = delete;
    Minesweeper& operator=(const Minesweeper&) = delete;

    Minesweeper(Minesweeper&&) = delete;
    Minesweeper& operator=(Minesweeper&&) = delete;

    void initGame(CellPosition firstRevealedCell);
    void revealCell(CellPosition cell);
    void markCell(CellPosition cell);

protected:
    virtual void onMineRevealed(const CellPosition& cell) = 0;
    virtual void onCellRevealead(const CellPosition& cell, unsigned minesAround) = 0;
    virtual void onCellFlagged(const CellPosition& cell) = 0;
    virtual void onCellFlagRemoved(const CellPosition& cell) = 0;

    ~Minesweeper() = default;

private:
    Board board_;
    size_t boardSize_;
    unsigned numberOfMines_;
};

}// namespace core
}// namespace minesweeper
