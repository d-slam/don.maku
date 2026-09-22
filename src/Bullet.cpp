#include "Bullet.hpp"

Bullet::Bullet(Texture2D texture, Vector2 startPosition, float speed)
	: texture_(texture), position_(startPosition), speed_(speed)
{
}

void Bullet::Update(float deltaTime)
{
	position_.y -= speed_ * deltaTime;
}

void Bullet::Draw() const
{
	DrawTextureV(texture_,
		{ position_.x - texture_.width / 2.0f, position_.y - texture_.height / 2.0f },
		WHITE);
}

bool Bullet::IsOffScreen(int screenHeight) const
{
	return position_.y + texture_.height / 2.0f < 0.0f;
}
