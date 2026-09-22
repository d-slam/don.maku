cmake_minimum_required(VERSION 3.20)

project(Danmaku
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(Danmaku
    src/main.cpp
    src/Game.cpp
    src/Player.cpp
    src/Bullet.cpp
    src/Control.cpp
)

target_link_libraries(Danmaku PRIVATE raylib)