#pragma once

#include <raylib.h>

class Control
{
public:
	Vector2 GetMovement() const;
	bool IsSlowMovement() const;
	bool IsShooting() const;
};
