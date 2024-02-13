#include "MineGenerator.hpp"
#include "Board.hpp"
#include <algorithm>
#include <numeric>
#include <random>
#include <stdexcept>

namespace minesweeper
{
namespace core
{

MineGenerator::MineGenerator(std::size_t boardSize) : boardSize_{ boardSize }
{
}

std::vector<CellPosition> MineGenerator::generateRandomPositionsWithoutRepetition(const CellPosition& firstReveleadCell,
  unsigned numberOfMines)
{
    if (boardSize_ * boardSize_ <= numberOfMines)
    {
        throw std::runtime_error("Too many mines");
    }

    std::vector<CellPosition> randomCells;
    randomCells.reserve(boardSize_ * boardSize_ - 1);
    for (std::size_t i = 0; i < boardSize_ * boardSize_; ++i)
    {
        if (i / boardSize_ != firstReveleadCell.x_ || i % boardSize_ != firstReveleadCell.y_)
        {
            randomCells.emplace_back(i / boardSize_, i % boardSize_);
        }
    }
    std::shuffle(randomCells.begin(), randomCells.end(), std::mt19937{ std::random_device{}() });
    randomCells.resize(numberOfMines);

    return randomCells;
}

}// namespace core
}// namespace minesweeper
