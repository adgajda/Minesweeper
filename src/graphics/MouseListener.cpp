#include "MouseListener.hpp"
#include <SFML/Window/Mouse.hpp>
#include <chrono>

namespace minesweeper
{
namespace graphics
{
namespace
{
struct LeftButton
{
    static constexpr auto value = sf::Mouse::Left;
};
struct MiddleButton
{
    static constexpr auto value = sf::Mouse::Middle;
};
struct RightButton
{
    static constexpr auto value = sf::Mouse::Right;
};

template<typename Button, typename Callback>
void handleButtonEvent(const Callback& callback, const core::CellPosition& cellPos)
{
    static bool isButtonAlreadyPressed = false;
    if (sf::Mouse::isButtonPressed(Button::value))
    {
        if (!isButtonAlreadyPressed && callback)
        {
            if constexpr (Button::value == MiddleButton::value)
            {
                callback();
            }
            else
            {
                callback(cellPos);
            }
        }
        isButtonAlreadyPressed = true;
    }
    else
    {
        isButtonAlreadyPressed = false;
    }
}
}// namespace

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
    const core::CellPosition cellPos(
      static_cast<unsigned int>(mousePosition.x) / cellSize, static_cast<unsigned int>(mousePosition.y) / cellSize);
    handleButtonEvent<LeftButton>(leftButtonCallBack_, cellPos);
    handleButtonEvent<RightButton>(rightButtonCallBack_, cellPos);
    handleButtonEvent<MiddleButton>(middleButtonCallBack_, cellPos);
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
