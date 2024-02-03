#pragma once
#include <cstddef>
#include <vector>

namespace minesweeper
{
namespace core
{

enum class State
{
    Empty,
    Mine,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
};

enum class VisibleState
{
    Revealed,
    Covered,
    Flagged,
};

struct Cell
{
    State state_ = State::Empty;
    VisibleState visibleState_ = VisibleState::Covered;
};

struct CellPosition
{
    CellPosition(size_t x, size_t y) : x_{ x }, y_{ y }
    {
    }
    size_t x_{ 0 };
    size_t y_{ 0 };
};

class Board
{
public:
    explicit Board(size_t boardSize);
    void initBoard(const std::vector<CellPosition>& minesPositions);
    void revealCell(const CellPosition& position);
    void flagCell(const CellPosition& position);
    void unflagCell(const CellPosition& position);
    [[nodiscard]] bool isCellRevealed(const CellPosition& position) const;
    [[nodiscard]] bool isCellFlagged(const CellPosition& position) const;
    [[nodiscard]] State getCellState(const CellPosition& position) const;

private:
    void placeMines(const std::vector<CellPosition>& minesPositions);
    void setNumberOfSurroundingMines();
    [[nodiscard]] State numberToState(unsigned number) const;

    std::vector<std::vector<Cell>> matrix_;
};

}// namespace core
}// namespace minesweeper
