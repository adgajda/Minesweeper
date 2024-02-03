
add_executable(Minesweeper 
    main.cpp 
    core/Board.cpp
    core/MineGenerator.cpp
    core/Minesweeper.cpp
    graphics/Game.cpp
)

target_link_libraries(Minesweeper PRIVATE sfml-graphics sfml-system sfml-window)
