#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>

namespace minesweeper
{
namespace core
{
struct CellPosition;
}

namespace graphics
{

class MouseListener final
{
public:
    void listen(sf::RenderWindow& window);
    void addLeftButtonCallback(std::function<void(const core::CellPosition&)>&& callback);
    void addRightButtonCallback(std::function<void(const core::CellPosition&)>&& callback);
    void addMiddleButtonCallback(std::function<void()>&& callback);

private:
    std::function<void(const core::CellPosition&)> leftButtonCallBack_;
    std::function<void(const core::CellPosition&)> rightButtonCallBack_;
    std::function<void()> middleButtonCallBack_;
};

}// namespace graphics
}// namespace minesweeper
