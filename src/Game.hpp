#pragma once

#include "Player.hpp"

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
};
