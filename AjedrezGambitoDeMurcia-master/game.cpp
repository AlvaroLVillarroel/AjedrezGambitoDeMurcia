
#include "game.h"
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"

/*
void Game::dibuja() {
	estado = inicio;
	//if (estado = inicio) 
	//{
	gluLookAt(0, 0, 40,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//dibuja pantalla de inicio

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

	//dibuja botones de empezar partida  y de salir del juego. Hay que ajustar los valores

	glBegin(GL_POLYGON); //empezar partida
	glVertex2f(-5, 5);
	glVertex2f(5, 5);
	glVertex2f(5, 2);
	glVertex2f(-5, 2);
	glEnd();

	glBegin(GL_POLYGON); //salir del juego
	glVertex2f(-5, 1);
	glVertex2f(5, 1);
	glVertex2f(5, -2);
	glVertex2f(-5, -2);
	glEnd();

	//}
	if (estado = modos) {

		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/modos.png").id);
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
} 

void Game::mousePress(int button, int state, int x, int y) {

	if(estado=inicio)
	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
		//Hay que ajustar valores acorde a las coord de los botones
			if (x >= -5 && x <= 5 && y >= 5 && y <= 2) {
				estado = modos;
			}
			else if (x >= -5 && x <= 5 && y >= 1 && y <= -2) {
				exit(0);
		}

		}
	}

}*/