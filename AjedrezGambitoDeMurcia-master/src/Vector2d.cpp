#include "Vector2d.h"

Vector2d::Vector2d() : x(0.0f), y(0.0f)
{
}

Vector2d::Vector2d(float x, float y) : x(x), y(y)
{
}

Vector2d Vector2d::operator+(const Vector2d& other) const
{
	return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(const Vector2d& other) const
{
	return Vector2d(x - other.x, y - other.y);
}

Vector2d Vector2d::operator*(float scalar) const
{
	return Vector2d(x * scalar, y * scalar);
}

Vector2d Vector2d::operator/(float scalar) const
{
	// Asegúrate de no dividir por cero
	if (scalar != 0.0f)
		return Vector2d(x / scalar, y / scalar);
	else
		return Vector2d(x, y);
}