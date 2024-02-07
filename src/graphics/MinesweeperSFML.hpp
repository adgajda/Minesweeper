#pragma once
#include "TexturesManager.hpp"
#include "core/Minesweeper.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace minesweeper
{
namespace core
{
struct CellPosition;
}

namespace graphics
{

enum class MinesweeperTextures;

class MinesweeperSFML final : public core::Minesweeper
{
public:
    MinesweeperSFML(std::size_t boardSize, unsigned numberOfMines);
    void draw(sf::RenderWindow& window);

private:
    void onGameLost(const core::CellPosition& cell) override;
    void onCellRevealed(const core::CellPosition& cell, unsigned minesAround) override;
    void onCellFlagged(const core::CellPosition& cell) override;
    void onCellFlagRemoved(const core::CellPosition& cell) override;
    void onRestart() override;
    void onGameWon() override;

    TexturesManager<MinesweeperTextures> texturesManager_;
    std::vector<std::vector<sf::Sprite>> cellSprites_;
};

}// namespace graphics
}// namespace minesweeper