#pragma once

#include <raylib.h>

class Bullet
{
public:
	Bullet(Texture2D texture, Vector2 startPosition, Vector2 direction, float speed);

	void Update(float deltaTime);
	void Draw() const;
	bool IsOffScreen(int screenHeight) const;
	bool CollidesWith(Rectangle target) const;

private:
	Texture2D texture_{};
	Vector2 position_{};
	Vector2 direction_{};
	float speed_{};
};
