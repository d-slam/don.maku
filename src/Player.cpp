#include "Player.hpp"

#include <algorithm>
#include <raymath.h>

Player::Player(const char* texturePath, Vector2 startPosition)
	: texture_(LoadTexture(texturePath)), position_(startPosition)
{
}

Player::~Player()
{
	UnloadTexture(texture_);
}

void Player::Update(float deltaTime, int screenWidth, int screenHeight)
{
	Vector2 direction{};

	if (IsKeyDown(KEY_W))
	{
		direction.y -= 1.0f;
	}
	if (IsKeyDown(KEY_S))
	{
		direction.y += 1.0f;
	}
	if (IsKeyDown(KEY_A))
	{
		direction.x -= 1.0f;
	}
	if (IsKeyDown(KEY_D))
	{
		direction.x += 1.0f;
	}

	if (direction.x != 0.0f || direction.y != 0.0f)
	{
		direction = Vector2Normalize(direction);
		const bool slowMovement = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
		const float movementSpeed = slowMovement ? speed_ * speedSlowFak_ : speed_;
		position_.x += direction.x * movementSpeed * deltaTime;
		position_.y += direction.y * movementSpeed * deltaTime;
	}

	const float halfWidth = static_cast<float>(texture_.width) / 2.0f;
	const float halfHeight = static_cast<float>(texture_.height) / 2.0f;
	position_.x = std::clamp(position_.x, halfWidth, screenWidth - halfWidth);
	position_.y = std::clamp(position_.y, halfHeight, screenHeight - halfHeight);
}

void Player::Draw() const
{
	DrawTextureV(texture_, { position_.x - texture_.width / 2.0f, position_.y - texture_.height / 2.0f }, WHITE);
}

Vector2 Player::GetPosition() const
{
	return position_;
}
