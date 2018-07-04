cmake_minimum_required(VERSION 3.8)
project(sources)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Bot.cpp
        Bullet.cpp
        Game.cpp
        Level.cpp
        main.cpp
        mainTest.cpp
        Map.cpp
        Player.cpp
        SpecialWeapon.cpp
        Turret.cpp
        Unit.cpp)

add_executable(sources ${SOURCE_FILES})