#include "Enemy.hpp"

#include <algorithm>
#include <cmath>

Enemy::Enemy(Vector2 startPosition)
	: position_(startPosition)
{
}

void Enemy::Update(float deltaTime, int screenWidth)
{
	time_ += deltaTime;
	position_.x += std::sin(time_ * 1.5f) * 80.0f * deltaTime;
	position_.x = std::clamp(position_.x, 40.0f, static_cast<float>(screenWidth) - 40.0f);
}

void Enemy::Draw() const
{
	if (!IsAlive())
	{
		return;
	}

	DrawRectangleV({ position_.x - 24.0f, position_.y - 18.0f }, { 48.0f, 36.0f }, RED);
	DrawRectangle(20, 20, 200, 12, DARKGRAY);
	DrawRectangle(20, 20, hp_ * 2, 12, GREEN);
}

void Enemy::TakeDamage(int damage)
{
	hp_ -= damage;
}

bool Enemy::IsAlive() const
{
	return hp_ > 0;
}

Rectangle Enemy::GetHitbox() const
{
	return { position_.x - 24.0f, position_.y - 18.0f, 48.0f, 36.0f };
}

Vector2 Enemy::GetPosition() const
{
	return position_;
}