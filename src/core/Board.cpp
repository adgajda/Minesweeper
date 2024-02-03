#include "Board.hpp"

namespace minesweeper
{
namespace core
{

Board::Board(size_t boardSize)
{
    matrix.resize(boardSize);
    for (auto& row : matrix)
    {
        row.resize(boardSize);
    }
}

void Board::initBoard(const std::vector<CellPosition>& minesPositions)
{
    placeMines(minesPositions);
    setNumberOfSurroundingMines();
}

void Board::flagCell(const CellPosition& position)
{
    matrix[position.x][position.y].visibleState = VisibleState::Flagged;
}

void Board::revealCell(const CellPosition& position)
{
    matrix[position.x][position.y].visibleState = VisibleState::Revealed;
}

bool Board::isCellRevealed(const CellPosition& position)
{
    return matrix[position.x][position.y].visibleState == VisibleState::Revealed;
}

bool Board::isCellFlagged(const CellPosition& position)
{
    return matrix[position.x][position.y].visibleState == VisibleState::Flagged;
}

State Board::getCellState(const CellPosition& position)
{
    return matrix[position.x][position.y].state;
}

void Board::placeMines(const std::vector<CellPosition>& minesPositions)
{
    for (const auto& [x, y] : minesPositions)
    {
        matrix[x][y].state = State::Mine;
    }
}

void Board::setNumberOfSurroundingMines()
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix.size(); ++j)
        {
            if (matrix[i][j].state == State::Mine)
            {
                continue;
            }

            unsigned minesCounter{ 0 };
            const auto isInRange = [this](size_t x, size_t y) { return x < matrix.size() && y < matrix.size(); };
            if (isInRange(i - 1, j - 1) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i - 1, j) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i - 1, j + 1) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i, j - 1) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i, j + 1) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i + 1, j - 1) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i + 1, j) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }
            if (isInRange(i + 1, j + 1) && matrix[i - 1][j].state == State::Mine)
            {
                ++minesCounter;
            }

            matrix[i][j].state = numberToState(minesCounter);
        }
    }
}

State Board::numberToState(unsigned number)
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

    throw("Too many mines");
}

}// namespace core
}// namespace minesweeper