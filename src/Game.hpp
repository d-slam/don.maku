#pragma once

#include "Bullet.hpp"
#include "Control.hpp"
#include "Enemy.hpp"
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
	enum class BossPattern
	{
		Single,
		RadialBurst,
		Spiral
	};

	void ShootRadialBurst();
	void ShootSpiral();

	int screenWidth_;
	int screenHeight_;
	Control control_;
	Player player_;
	Enemy enemy_;
	Texture2D bulletTexture_{};
	std::vector<Bullet> playerBullets_;
	std::vector<Bullet> enemyBullets_;
	float shotCooldown_ = 0.0f;
	float enemyShotCooldown_ = 0.0f;
	BossPattern bossPattern_ = BossPattern::Single;
	float bossPatternTimer_ = 0.0f;
	float spiralAngle_ = 0.0f;
};
