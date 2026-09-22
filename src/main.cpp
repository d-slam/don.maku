#include "Game.hpp"

#include <raylib.h>

int main()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Danmaku");

    {
        Game game(screenWidth, screenHeight);
        game.Run();
    }

    CloseWindow();
}