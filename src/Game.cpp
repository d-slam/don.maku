#include "Game.hpp"

#include <raylib.h>

Game::Game(int screenWidth, int screenHeight)
	: screenWidth_(screenWidth),
	  screenHeight_(screenHeight),
	  player_("assets/player.png", { screenWidth / 2.0f, screenHeight - 100.0f })
{
}

Game::~Game()
{
}

void Game::Run()
{
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		player_.Update(GetFrameTime(), screenWidth_, screenHeight_);

		BeginDrawing();
		ClearBackground(BLACK);
		player_.Draw();
		EndDrawing();
	}
}
