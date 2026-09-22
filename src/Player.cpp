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

void Player::Update(float deltaTime, int screenWidth, int screenHeight, const Control& control)
{
	if (!IsAlive())
	{
		return;
	}

	Vector2 direction = control.GetMovement();

	if (direction.x != 0.0f || direction.y != 0.0f)
	{
		direction = Vector2Normalize(direction);
		const float movementSpeed = control.IsSlowMovement() ? speed_ * speedSlowFak_ : speed_;
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

	constexpr int barWidth = 160;
	constexpr int barHeight = 12;
	const int barX = 20;
	const int barY = 20;
	DrawRectangle(barX, barY, barWidth, barHeight, DARKGRAY);
	DrawRectangle(barX, barY, barWidth * health_ / maxHealth_, barHeight, GREEN);
	DrawText(TextFormat("HP: %d/%d", health_, maxHealth_), barX, barY + barHeight + 4, 18, WHITE);
}

Vector2 Player::GetPosition() const
{
	return position_;
}

Rectangle Player::GetHitbox() const
{
	constexpr float hitboxSize = 8.0f;
	return { position_.x - hitboxSize / 2.0f, position_.y - hitboxSize / 2.0f, hitboxSize, hitboxSize };
}

void Player::TakeDamage(int damage)
{
	health_ = std::max(0, health_ - damage);
}

bool Player::IsAlive() const
{
	return health_ > 0;
}
