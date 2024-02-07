#pragma once
#include <array>
#include <cstddef>
#include <stdexcept>
#include <utility>
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
    CellPosition(std::size_t x, std::size_t y) : x_{ x }, y_{ y }
    {
    }
    std::size_t x_{ 0 };
    std::size_t y_{ 0 };
};

inline constexpr std::array<std::pair<int, int>, 8> cellNeighbors = {
    { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } }
};

class Board final
{
public:
    Board(std::size_t boardSize, const std::vector<CellPosition>& minesPositions);
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
    std::size_t boardSize_;
    unsigned numberOfMines_ = 0;
    unsigned cellsRevealed_ = 0;
};

}// namespace core
}// namespace minesweeper
