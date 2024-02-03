#include "MouseListener.hpp"
#include <SFML/Window/Mouse.hpp>

namespace minesweeper
{
namespace graphics
{

void MouseListener::listen(sf::RenderWindow& window)
{
    const auto mousePosition = sf::Mouse::getPosition(window);
    static const auto windowSize = window.getSize();
    if (mousePosition.x < 0 || mousePosition.y < 0 || static_cast<unsigned int>(mousePosition.x) > windowSize.x
        || static_cast<unsigned int>(mousePosition.y) > windowSize.y)
    {
        return;
    }

    const unsigned cellSize{ 21 };
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        const core::CellPosition cellPos(
          static_cast<unsigned int>(mousePosition.x) / cellSize, static_cast<unsigned int>(mousePosition.y) / cellSize);
        if (leftButtonCallBack_)
        {
            leftButtonCallBack_(cellPos);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        const core::CellPosition cellPos(
          static_cast<unsigned int>(mousePosition.x) / cellSize, static_cast<unsigned int>(mousePosition.y) / cellSize);
        if (rightButtonCallBack_)
        {
            rightButtonCallBack_(cellPos);
        }
    }
}

void MouseListener::addLeftButtonCallback(std::function<void(core::CellPosition)>&& callback)
{
    leftButtonCallBack_ = std::move(callback);
}

void MouseListener::addRightButtonCallback(std::function<void(core::CellPosition)>&& callback)
{
    rightButtonCallBack_ = std::move(callback);
}


}// namespace graphics
}// namespace minesweeper
