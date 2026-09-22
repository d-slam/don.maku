#pragma once

#include "Bullet.hpp"
#include "Player.hpp"

#include <vector>

class Game
{
public:
	Game(int screenWidth, int screenHeight);
	~Game();

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void Run();

private:
	int screenWidth_;
	int screenHeight_;
	Player player_;
	Texture2D bulletTexture_{};
	std::vector<Bullet> bullets_;
	float shotCooldown_ = 0.0f;
};
