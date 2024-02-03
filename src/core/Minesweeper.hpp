#pragma once

namespace minesweeper
{
namespace core
{

class Minesweeper
{
public:
    Minesweeper();

    Minesweeper(const Minesweeper&) = delete;
    Minesweeper& operator=(const Minesweeper&) = delete;

    Minesweeper(Minesweeper&&) = delete;
    Minesweeper& operator=(Minesweeper&&) = delete;

    void revealCell();
    void markCell();

protected:
    virtual void onMineRevealed() = 0;
    virtual void onCellRevealead() = 0;
    virtual void onCellFlagged() = 0;
    virtual void onGameLost() = 0;

    ~Minesweeper() = default;

private:
};

}// namespace core
}// namespace minesweeper
