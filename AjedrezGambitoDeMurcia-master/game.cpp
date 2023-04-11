
#include "game.h"
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"

void Game::dibuja() {
	//estado = inicio;

	gluLookAt(0, 0, 40,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portada.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(-17.6f, -8.8f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(17.6f, -8.8f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(17.6f, 8.8f, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(-17.6f, 8.8f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

} 

void Game::mousePress(int button, int state, int x, int y) {

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{


	}

}