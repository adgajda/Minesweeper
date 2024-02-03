#pragma once
#include "Board.hpp"
#include <cstddef>
#include <vector>

namespace minesweeper
{
namespace core
{

class MineGenerator final
{
public:
    explicit MineGenerator(size_t boardSize);
    [[nodiscard]] std::vector<CellPosition>
      generateRandomPositionsWithoutRepetition(const CellPosition& firstReveleadCell, unsigned numberOfMines);

private:
    size_t boardSize_;
};

}// namespace core
}// namespace minesweeper
