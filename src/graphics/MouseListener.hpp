#pragma once
#include "core/Board.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>

namespace minesweeper
{
namespace graphics
{

class MouseListener
{
public:
    void listen(sf::RenderWindow& window);
    void addLeftButtonCallback(std::function<void(core::CellPosition)>&& callback);
    void addRightButtonCallback(std::function<void(core::CellPosition)>&& callback);

private:
    std::function<void(core::CellPosition)> leftButtonCallBack_;
    std::function<void(core::CellPosition)> rightButtonCallBack_;
};

}// namespace graphics
}// namespace minesweeper