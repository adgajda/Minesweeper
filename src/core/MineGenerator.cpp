#include "MineGenerator.hpp"
#include <algorithm>
#include <numeric>
#include <random>
#include <stdexcept>

namespace minesweeper
{
namespace core
{

MineGenerator::MineGenerator(size_t boardSize) : boardSize_{ boardSize }
{
}

std::vector<CellPosition> MineGenerator::generateRandomPositionsWithoutRepetition(const CellPosition& firstReveleadCell,
  unsigned numberOfMines)
{
    if (boardSize_ * boardSize_ <= numberOfMines)
    {
        throw std::runtime_error("Too many mines");
    }

    std::vector<size_t> randomCells(boardSize_ * boardSize_);
    std::iota(randomCells.begin(), randomCells.end(), 0);
    std::shuffle(randomCells.begin(), randomCells.end(), std::mt19937{ std::random_device{}() });

    const size_t firstCell{ firstReveleadCell.x_ * boardSize_ + firstReveleadCell.y_ };
    std::vector<CellPosition> retVal;
    retVal.reserve(numberOfMines);
    for (unsigned i = 0; i < numberOfMines; ++i)
    {
        if (randomCells[i] == firstCell)
        {
            continue;
        }
        retVal.emplace_back(randomCells[i] / boardSize_, randomCells[i] % boardSize_);
    }

    return retVal;
}

}// namespace core
}// namespace minesweeper
