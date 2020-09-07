cmake_minimum_required(VERSION 3.13)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 14)

add_executable(tic_tac_toe main.cpp Board.cpp Board.h Game.h AbstractPlayer.h AbstractPlayer.cpp Game.cpp Computer.cpp Computer.h Player.cpp Player.h)