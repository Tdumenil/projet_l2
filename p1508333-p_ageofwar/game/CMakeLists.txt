cmake_minimum_required(VERSION 3.6)
project(game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/core/sources/Bullet.cpp src/core/headers/Bullet.h src/core/sources/mainTest.cpp src/core/sources/Unit.cpp src/core/headers/Unit.h src/core/sources/Turret.cpp src/core/headers/Turret.h src/core/sources/SpecialWeapon.cpp src/core/headers/SpecialWeapon.h src/core/sources/Level.cpp src/core/headers/Level.h src/core/sources/Player.cpp src/core/headers/Player.h src/core/sources/Map.cpp src/core/headers/Map.h src/core/sources/Game.cpp src/core/headers/Game.h src/txtGame/sources/txtGame.cpp src/txtGame/sources/mainTxt.cpp src/txtGame/headers/txtGame.h src/core/sources/Bot.cpp src/core/headers/Bot.h src/sdlGame/sources/mainSdl.cpp src/sdlGame/sources/sdlGame.cpp src/sdlGame/headers/sdlGame.h src/sdlGame/sources/Image.cpp src/sdlGame/headers/Image.h src/sdlGame/sources/Font.cpp src/sdlGame/headers/Font.h src/sdlGame/sources/Sound.cpp src/sdlGame/headers/Sound.h)
add_executable(game ${SOURCE_FILES})