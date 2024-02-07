#include "graphics/Game.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::size_t boardSize{ 21 };
    unsigned numberOfMines{ 80 };
    if (argc == 2)
    {
        const std::string difficultyLevel(argv[1]);
        if (difficultyLevel == "easy")
        {
            boardSize = 9;
            numberOfMines = 10;
        }
        else if (difficultyLevel == "medium")
        {
            boardSize = 16;
            numberOfMines = 40;
        }
        else if (difficultyLevel == "hard")
        {
            boardSize = 21;
            numberOfMines = 99;
        }
        else
        {
            std::cout << "Wrong arguments\n";
            return 0;
        }
    }

    minesweeper::graphics::Game game(boardSize, numberOfMines);
    game.play();
    return 0;
}