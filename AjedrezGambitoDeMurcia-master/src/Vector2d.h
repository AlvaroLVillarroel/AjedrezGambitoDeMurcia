#pragma once

class Vector2d {

public:
	float x;
	float y;

	Vector2d();
	Vector2d(float x, float y);

	Vector2d operator+(const Vector2d& other) const;
	Vector2d operator-(const Vector2d& other) const;
	Vector2d operator*(float scalar) const;
	Vector2d operator/(float scalar) const;
};


