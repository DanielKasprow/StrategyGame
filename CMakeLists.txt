cmake_minimum_required(VERSION 3.22)
project(tietoevryTaskGame-master)

set(CMAKE_CXX_STANDARD 17)

add_executable(tietoevryTaskGame-master main.cpp Units/FightingUnit.cpp Units/Unit.cpp Interfaces/UnitsFightingActions.cpp Units/Base.cpp Units Board/LoadBoard.cpp Player/Player.cpp)
include_directories(Headers)

