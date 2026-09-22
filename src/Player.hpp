#pragma once

#include <raylib.h>

class Player
{
public:
	Player(const char* texturePath, Vector2 startPosition);
	~Player();

	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;

	void Update(float deltaTime, int screenWidth, int screenHeight);
	void Draw() const;

private:
	Texture2D texture_{};
	Vector2 position_{};
	float speed_ = 300.0f;
};
