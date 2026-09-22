#include "Bullet.hpp"

Bullet::Bullet(Texture2D texture, Vector2 startPosition, Vector2 direction, float speed)
	: texture_(texture), position_(startPosition), direction_(direction), speed_(speed)
{
}

void Bullet::Update(float deltaTime)
{
	position_.x += direction_.x * speed_ * deltaTime;
	position_.y += direction_.y * speed_ * deltaTime;
}

void Bullet::Draw() const
{
	DrawTextureV(texture_,
		{ position_.x - texture_.width / 2.0f, position_.y - texture_.height / 2.0f },
		WHITE);
}

bool Bullet::IsOffScreen(int screenHeight) const
{
	return position_.x + texture_.width / 2.0f < 0.0f
		|| position_.x - texture_.width / 2.0f > GetScreenWidth()
		|| position_.y + texture_.height / 2.0f < 0.0f
		|| position_.y - texture_.height / 2.0f > screenHeight;
}

bool Bullet::CollidesWith(Rectangle target) const
{
	return CheckCollisionPointRec(position_, target);
}
