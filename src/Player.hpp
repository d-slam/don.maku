#pragma once

#include "Control.hpp"

#include <raylib.h>

class Player
{
public:
	Player(const char* texturePath, Vector2 startPosition);
	~Player();

	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	void Update(float deltaTime, int screenWidth, int screenHeight, const Control& control);
	void Draw() const;
	Vector2 GetPosition() const;

private:
	Texture2D texture_{};
	Vector2 position_{};
	float speed_ = 800.0f;
    float speedSlowFak_ = 0.4f;
};
