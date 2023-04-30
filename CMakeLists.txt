cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Headers/Units.h Units/Knight.cpp Units/Unit.cpp Interfaces/UnitsFightingActions.cpp Units/Base.cpp Units/Swordsman.cpp Units/Archer.cpp Units/Catapult.cpp Units/Worker.cpp Units/Pikeman.cpp Units Interfaces/WorkerUnitActions.cpp Headers/Board.h Board/LoadBoard.cpp Player/Player.cpp Headers/Player.h)
include_directories(Units )

