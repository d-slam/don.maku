#pragma once

#include <raylib.h>

class Bullet
{
public:
	Bullet(Texture2D texture, Vector2 startPosition, float speed);

	void Update(float deltaTime);
	void Draw() const;
	bool IsOffScreen(int screenHeight) const;

private:
	Texture2D texture_{};
	Vector2 position_{};
	float speed_{};
};
