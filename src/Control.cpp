#include "Control.hpp"

Vector2 Control::GetMovement() const
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

	return direction;
}

bool Control::IsSlowMovement() const
{
	return IsKeyDown(KEY_SPACE);
    
}

bool Control::IsShooting() const
{
	return IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
}
