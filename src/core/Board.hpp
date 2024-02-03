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
    State state = State::Empty;
    VisibleState visibleState = VisibleState::Covered;
};

struct CellPosition
{
    size_t x{ 0 };
    size_t y{ 0 };
};

class Board
{
public:
    Board(size_t boardSize);
    void initBoard(const std::vector<CellPosition>& minesPositions);
    void revealCell(const CellPosition& position);
    void flagCell(const CellPosition& position);
    bool isCellRevealed(const CellPosition& position);
    bool isCellFlagged(const CellPosition& position);
    State getCellState(const CellPosition& position);

private:
    void placeMines(const std::vector<CellPosition>& minesPositions);
    void setNumberOfSurroundingMines();
    State numberToState(unsigned number);

    std::vector<std::vector<Cell>> matrix;
};

}// namespace core
}// namespace minesweeper
