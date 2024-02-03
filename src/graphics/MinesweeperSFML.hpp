#pragma once
#include "core/Minesweeper.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

namespace minesweeper
{
namespace graphics
{

class MinesweeperSFML final : public core::Minesweeper
{
public:
    MinesweeperSFML();
    void draw(sf::RenderWindow& window);

private:
    void onMineRevealed(const core::CellPosition& cell) override;
    void onCellRevealed(const core::CellPosition& cell, unsigned minesAround) override;
    void onCellFlagged(const core::CellPosition& cell) override;
    void onCellFlagRemoved(const core::CellPosition& cell) override;
};

}// namespace graphics
}// namespace minesweeper