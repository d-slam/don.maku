#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Danmaku");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Danmaku", 20, 20, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();
}