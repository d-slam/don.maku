#pragma once

#include <raylib.h>

class Enemy
{
public:
	Enemy(Vector2 startPosition);

	void Update(float deltaTime, int screenWidth);
	void Draw() const;
	void TakeDamage(int damage);
	bool IsAlive() const;
	Rectangle GetHitbox() const;
	Vector2 GetPosition() const;

private:
	Vector2 position_{};
	float time_{};
	int hp_ = 100;
};