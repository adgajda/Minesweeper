#pragma once
#include "TexturesManager.hpp"
#include "core/MinesweeperCRTP.hpp"
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

class MinesweeperSFML final : public core::MinesweeperCRTP<MinesweeperSFML>
{
public:
    MinesweeperSFML(std::size_t boardSize, unsigned numberOfMines);
    void draw(sf::RenderWindow& window);

private:
    friend MinesweeperCRTP;
    void onCellRevealed(const core::CellPosition& cell, unsigned minesAround);
    void onCellFlagged(const core::CellPosition& cell);
    void onCellFlagRemoved(const core::CellPosition& cell);
    void onGameLost(const core::CellPosition& cell);
    void onGameWon();
    void onRestart();

    TexturesManager<MinesweeperTextures> texturesManager_;
    std::vector<std::vector<sf::Sprite>> cellSprites_;
};

}// namespace graphics
}// namespace minesweeper