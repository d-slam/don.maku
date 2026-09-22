#include "Game.hpp"

#include <algorithm>
#include <raylib.h>

Game::Game(int screenWidth, int screenHeight)
	: screenWidth_(screenWidth),
	  screenHeight_(screenHeight),
	  player_("assets/player.png", { screenWidth / 2.0f, screenHeight - 100.0f }),
	  bulletTexture_(LoadTexture("assets/bullets/bulletA.png"))
{
}

Game::~Game()
{
	UnloadTexture(bulletTexture_);
}

void Game::Run()
{
	SetTargetFPS(144);

	while (!WindowShouldClose())
	{
		const float deltaTime = GetFrameTime();
		player_.Update(deltaTime, screenWidth_, screenHeight_, control_);

		shotCooldown_ -= deltaTime;
		if (control_.IsShooting() && shotCooldown_ <= 0.0f)
		{
			bullets_.emplace_back(bulletTexture_, player_.GetPosition(), 1000.0f);
			shotCooldown_ = 0.1f;
		}

		for (Bullet& bullet : bullets_)
		{
			bullet.Update(deltaTime);
		}
		bullets_.erase(
			std::remove_if(bullets_.begin(), bullets_.end(), [this](const Bullet& bullet)
			{
				return bullet.IsOffScreen(screenHeight_);
			}),
			bullets_.end());

		BeginDrawing();
		ClearBackground(BLACK);
		for (const Bullet& bullet : bullets_)
		{
			bullet.Draw();
		}
		player_.Draw();
		EndDrawing();
	}
}
