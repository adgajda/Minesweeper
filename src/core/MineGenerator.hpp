#pragma once
#include <cstddef>
#include <vector>

namespace minesweeper
{
namespace core
{
struct CellPosition;

class MineGenerator final
{
public:
    explicit MineGenerator(std::size_t boardSize);
    [[nodiscard]] std::vector<CellPosition>
      generateRandomPositionsWithoutRepetition(const CellPosition& firstReveleadCell, unsigned numberOfMines);

private:
    std::size_t boardSize_;
};

}// namespace core
}// namespace minesweeper
