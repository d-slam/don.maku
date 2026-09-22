#include "Game.hpp"

#include <algorithm>
#include <raylib.h>

Game::Game(int screenWidth, int screenHeight)
	: screenWidth_(screenWidth),
	  screenHeight_(screenHeight),
	  player_("assets/player.png", { screenWidth / 2.0f, screenHeight - 100.0f }),
	  enemy_({ screenWidth / 2.0f, 120.0f }),
	  bulletTexture_(LoadTexture("assets/bullets/bulletA.png"))
{
	playerBullets_.reserve(5000);
	enemyBullets_.reserve(5000);
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
		enemy_.Update(deltaTime, screenWidth_);

		shotCooldown_ -= deltaTime;
		if (player_.IsAlive() && control_.IsShooting() && shotCooldown_ <= 0.0f)
		{
			playerBullets_.emplace_back(bulletTexture_, player_.GetPosition(), Vector2{ 0.0f, -1.0f }, 1000.0f);
			shotCooldown_ = 0.1f;
		}

		enemyShotCooldown_ -= deltaTime;
		if (enemy_.IsAlive() && enemyShotCooldown_ <= 0.0f)
		{
			enemyBullets_.emplace_back(bulletTexture_, enemy_.GetPosition(), Vector2{ 0.0f, 1.0f }, 260.0f);
			enemyShotCooldown_ = 0.25f;
		}

		for (Bullet& bullet : playerBullets_)
		{
			bullet.Update(deltaTime);
		}
		for (Bullet& bullet : enemyBullets_)
		{
			bullet.Update(deltaTime);
		}

		for (const Bullet& bullet : playerBullets_)
		{
			if (enemy_.IsAlive() && bullet.CollidesWith(enemy_.GetHitbox()))
			{
				enemy_.TakeDamage(10);
			}
		}

		playerBullets_.erase(
			std::remove_if(playerBullets_.begin(), playerBullets_.end(), [this](const Bullet& bullet)
			{
				return bullet.IsOffScreen(screenHeight_) || bullet.CollidesWith(enemy_.GetHitbox());
			}),
			playerBullets_.end());
		enemyBullets_.erase(
			std::remove_if(enemyBullets_.begin(), enemyBullets_.end(), [this](const Bullet& bullet)
			{
				if (bullet.CollidesWith(player_.GetHitbox()))
				{
					player_.TakeDamage(1);
					return true;
				}
				return bullet.IsOffScreen(screenHeight_);
			}),
			enemyBullets_.end());

		BeginDrawing();
		ClearBackground(BLACK);
		for (const Bullet& bullet : enemyBullets_)
		{
			bullet.Draw();
		}
		for (const Bullet& bullet : playerBullets_)
		{
			bullet.Draw();
		}
		enemy_.Draw();
		player_.Draw();
		if (!player_.IsAlive())
		{
			DrawText("GAME OVER", screenWidth_ / 2 - 90, screenHeight_ / 2 - 20, 36, RED);
		}
		EndDrawing();
	}
}
