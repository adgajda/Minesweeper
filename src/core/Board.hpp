#pragma once
#include <cstddef>
#include <stdexcept>
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

[[nodiscard]] inline unsigned StateToNumber(State state)
{
    switch (state)
    {
    case State::Empty:
        return 0;
    case State::One:
        return 1;
    case State::Two:
        return 2;
    case State::Three:
        return 3;
    case State::Four:
        return 4;
    case State::Five:
        return 5;
    case State::Six:
        return 6;
    case State::Seven:
        return 7;
    case State::Eight:
        return 8;
    case State::Mine:
        break;
    }

    throw std::runtime_error("Invalid State");
}

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

class Board final
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
    [[nodiscard]] bool isGameWon() const;
    [[nodiscard]] std::vector<CellPosition> getMinesPositions() const;

private:
    void placeMines(const std::vector<CellPosition>& minesPositions);
    void setNumberOfSurroundingMines();
    [[nodiscard]] State numberToState(unsigned number) const;

    std::vector<std::vector<Cell>> matrix_;
    std::vector<CellPosition> mines_;
    size_t boardSize_;
    unsigned numberOfMines_ = 0;
    unsigned cellsRevealed_ = 0;
};

}// namespace core
}// namespace minesweeper
