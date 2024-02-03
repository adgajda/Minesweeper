#pragma once
#include "TexturesManager.hpp"
#include "core/Minesweeper.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace minesweeper
{
namespace graphics
{

class MinesweeperSFML final : public core::Minesweeper
{
public:
    MinesweeperSFML(size_t boardSize, unsigned numberOfMines);
    void draw(sf::RenderWindow& window);

private:
    void onMineRevealed(const core::CellPosition& cell) override;
    void onCellRevealed(const core::CellPosition& cell, unsigned minesAround) override;
    void onCellFlagged(const core::CellPosition& cell) override;
    void onCellFlagRemoved(const core::CellPosition& cell) override;
    void onRestart() override;

    TexturesManager<MinesweeperTextures> texturesManager_;
    std::vector<std::vector<sf::Sprite>> cellSprites_;
};

}// namespace graphics
}// namespace minesweeper