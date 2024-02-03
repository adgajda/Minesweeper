#include "MouseListener.hpp"
#include <SFML/Window/Mouse.hpp>
#include <chrono>

namespace minesweeper
{
namespace graphics
{

void MouseListener::listen(sf::RenderWindow& window)
{
    static auto lastButtonPressTime = std::chrono::high_resolution_clock::now();
    const auto timeFromLastButtonPressed = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - lastButtonPressTime);
    if (timeFromLastButtonPressed < std::chrono::milliseconds(150))
    {
        return;
    }

    const auto mousePosition = sf::Mouse::getPosition(window);
    static const auto windowSize = window.getSize();
    if (mousePosition.x < 0 || mousePosition.y < 0 || static_cast<unsigned int>(mousePosition.x) > windowSize.x
        || static_cast<unsigned int>(mousePosition.y) > windowSize.y)
    {
        return;
    }

    const unsigned cellSize{ 21 };
    const core::CellPosition cellPos(
      static_cast<unsigned int>(mousePosition.x) / cellSize, static_cast<unsigned int>(mousePosition.y) / cellSize);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (leftButtonCallBack_)
        {
            lastButtonPressTime = std::chrono::high_resolution_clock::now();
            leftButtonCallBack_(cellPos);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        if (rightButtonCallBack_)
        {
            lastButtonPressTime = std::chrono::high_resolution_clock::now();
            rightButtonCallBack_(cellPos);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
    {
        if (middleButtonCallBack_)
        {
            lastButtonPressTime = std::chrono::high_resolution_clock::now();
            middleButtonCallBack_();
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

void MouseListener::addMiddleButtonCallback(std::function<void()>&& callback)
{
    middleButtonCallBack_ = std::move(callback);
}

}// namespace graphics
}// namespace minesweeper
