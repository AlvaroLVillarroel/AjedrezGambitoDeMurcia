#include "player.h"

player::player()
{
	/*glPushMatrix();
	glTranslatef(position.x, position.y, 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glScaled(scale, scale, scale);
	sprite.draw();
	setVel(5.0f, 0.0f);
	glPopMatrix();*/
	//sprite.setSize(2, 2);
	position.x = -5;
	position.y = 0;
	//velocity.x = 0.15f;
	//velocity.y = 0.0f;
}

void player::dibuja()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, 2);
	glColor3f(1.0f, 0.0f, 0.0f);
	glScaled(0.005, 0.005, 0.005);
	if (velocity.x > 0.01)sprite.flip(false, false);
	if (velocity.x < -0.01)sprite.flip(true, false);
	if ((velocity.x < 0.01) && (velocity.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();
}

void player::setVel(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

void player::setPos(float ix, float iy)
{
	position.x = ix;
	position.y = iy;
}

void player::mueve(float dt)
{
	position = position + velocity * dt;

	// Si el jugador se sale de la pantalla, reiniciar su posición
	if (position.y > 1.0f)
		position.y = 0.0f;
}

Vector2d player::getPos()
{
	return position;
}
