
add_executable(minesweeper 
    main.cpp 
    core/Board.cpp
    core/MineGenerator.cpp
    core/Minesweeper.cpp
    graphics/Game.cpp
    graphics/MinesweeperSFML.cpp
    graphics/MouseListener.cpp
)

target_include_directories(minesweeper PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(minesweeper PRIVATE sfml-graphics sfml-system sfml-window)
