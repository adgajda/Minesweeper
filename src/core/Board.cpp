#include "Board.hpp"

namespace minesweeper
{
namespace core
{

Board::Board(size_t boardSize) : boardSize_{ boardSize }
{
}

void Board::initBoard(const std::vector<CellPosition>& minesPositions)
{
    mines_ = minesPositions;
    numberOfMines_ = minesPositions.size();
    cellsRevealed_ = 0;
    matrix_.clear();
    matrix_.resize(boardSize_);
    for (auto& row : matrix_)
    {
        row.resize(boardSize_);
    }
    placeMines(minesPositions);
    setNumberOfSurroundingMines();
}

bool Board::isGameWon() const
{
    const auto numberOfCells{ boardSize_ * boardSize_ };
    const auto cellsLeft{ numberOfCells - cellsRevealed_ };
    return cellsLeft == numberOfMines_;
}

std::vector<CellPosition> Board::getMinesPositions() const
{
    return mines_;
}

void Board::flagCell(const CellPosition& position)
{
    matrix_[position.x_][position.y_].visibleState_ = VisibleState::Flagged;
}

void Board::unflagCell(const CellPosition& position)
{
    matrix_[position.x_][position.y_].visibleState_ = VisibleState::Covered;
}

void Board::revealCell(const CellPosition& position)
{
    ++cellsRevealed_;
    matrix_[position.x_][position.y_].visibleState_ = VisibleState::Revealed;
}

bool Board::isCellRevealed(const CellPosition& position) const
{
    return matrix_[position.x_][position.y_].visibleState_ == VisibleState::Revealed;
}

bool Board::isCellFlagged(const CellPosition& position) const
{
    return matrix_[position.x_][position.y_].visibleState_ == VisibleState::Flagged;
}

State Board::getCellState(const CellPosition& position) const
{
    return matrix_[position.x_][position.y_].state_;
}

void Board::placeMines(const std::vector<CellPosition>& minesPositions)
{
    for (const auto& [x, y] : minesPositions)
    {
        matrix_[x][y].state_ = State::Mine;
    }
}

void Board::setNumberOfSurroundingMines()
{
    for (size_t i = 0; i < matrix_.size(); ++i)
    {
        for (size_t j = 0; j < matrix_.size(); ++j)
        {
            if (matrix_[i][j].state_ == State::Mine)
            {
                continue;
            }

            unsigned minesCounter{ 0 };
            const auto isCellValid = [this](const CellPosition& cellPos) {
                return cellPos.x_ < matrix_.size() && cellPos.y_ < matrix_.size();
            };
            for (const auto& neighbor : cellNeighbors)
            {
                const CellPosition cellToReveal(
                  i + static_cast<size_t>(neighbor.first), j + static_cast<size_t>(neighbor.second));
                if (isCellValid(cellToReveal) && matrix_[cellToReveal.x_][cellToReveal.y_].state_ == State::Mine)
                {
                    ++minesCounter;
                }
            }
            matrix_[i][j].state_ = numberToState(minesCounter);
        }
    }
}

State Board::numberToState(unsigned number) const
{
    switch (number)
    {
    case 0:
        return State::Empty;
    case 1:
        return State::One;
    case 2:
        return State::Two;
    case 3:
        return State::Three;
    case 4:
        return State::Four;
    case 5:
        return State::Five;
    case 6:
        return State::Six;
    case 7:
        return State::Seven;
    case 8:
        return State::Eight;
    }

    throw std::runtime_error("Too many mines");
}

}// namespace core
}// namespace minesweeper