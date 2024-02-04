# Minesweeper

Welcome to the Minesweeper project! This is just my one weekend project made for fun, and it's built using SFML (Simple and Fast Multimedia Library) to handle graphics and interactions. I'm happy to help or provide any further information to anyone who's interested in the project. Feel free to reach out if you have questions, suggestions, or if you'd like to contribute in any way!

# How To Play

Getting started with Minesweeper is easy, but mastering it requires careful thought and strategy. Here's how you can control the game:

- **Left Mouse Button (LMB)**: Use the left mouse button to reveal what is hidden in a cell. Be careful, though! If you reveal a mine, the game is over.

- **Right Mouse Button (RPM)**: Think you've spotted a mine? Use the right mouse button to place a flag on a cell. This marks the cell as dangerous, allowing you to avoid it as you continue to clear the board.

- **Middle Mouse Button**: Made a mistake or want to start over? Simply press the middle mouse button to restart the game at any time. This gives you a fresh board and a new opportunity to test your minesweeping skills.


# Prerequisites

Before you begin, ensure you have the following tools installed on your system:

- CMake (version 3.22 or higher)
- GCC (tested on GCC 13.2.0)
- SFML 2.6

# Build and Run

```
mkdir build && cd build
cmake ..
cmake --build .
./src/minesweeper
```
