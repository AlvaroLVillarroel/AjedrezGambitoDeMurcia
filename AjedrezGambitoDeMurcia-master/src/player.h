#pragma once
#include "ETSIDI.h"
#include <Vector2d.h>
using ETSIDI::SpriteSequence;
class player
{

	SpriteSequence sprite{ "fotos/pp.png", 5 };
	Vector2d position; // Posici�n actual del jugador
	Vector2d velocity; // Velocidad del jugador
	float scale; // Escala del sprite del jugador
public:
	player();
	void dibuja();
	void setVel(float vx, float vy);
	void setPos(float ix, float iy);
	void mueve(float dt);
	Vector2d getPos();

};



