#pragma once
#include "ETSIDI.h"
#include <Vector2d.h>
using ETSIDI::SpriteSequence;
class player
{

	SpriteSequence sprite{ "fotos/player.png", 5 };
	Vector2d position; // Posición actual del jugador
	Vector2d velocity; // Velocidad del jugador
	float scale; // Escala del sprite del jugador
public:
	player();
	void dibuja();
	void mueve(float dt);

};



