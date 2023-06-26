#include "player.h"

player::player()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glScaled(scale, scale, scale);
	sprite.draw();
	glPopMatrix();
}

void player::dibuja()
{
	glPushMatrix();
	glTranslatef(-5, 0, 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glScaled(0.005, 0.005, 0.005);
	sprite.draw();
	glPopMatrix();
}

void player::mueve(float dt)
{
	position = position + velocity * dt;

	// Si el jugador se sale de la pantalla, reiniciar su posición
	if (position.x > 1.0f)
		position.x = -1.0f;
}
