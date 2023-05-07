cmake_minimum_required(VERSION 3.22)
project(tietoevryTaskGame-master)

set(CMAKE_CXX_STANDARD 17)

add_executable(tietoevryTaskGame-master main.cpp Headers/Units.h Units/FightingUnit.cpp Units/Unit.cpp Interfaces/UnitsFightingActions.cpp Units/Base.cpp Units Headers/Board.h Board/LoadBoard.cpp Player/Player.cpp Headers/Player.h)
include_directories(Units )

