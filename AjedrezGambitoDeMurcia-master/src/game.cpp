
#include "game.h"
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"


Game::Game()
{
	estado = inicioPartida;
}

void Game::dibuja() {

	if (estado == inicioPartida) 
	{
	gluLookAt(0, 0, 40,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//dibuja pantalla de inicio

	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/pantallaInicio.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1); glVertex3f(-28.0f, -20.0f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(28.0f, -20.0f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(28.0f, 20.0f, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(-28.0f, 20.0f, 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	//dibuja botones de empezar partida  y de salir del juego. valores ya ajustados!

	glBegin(GL_POLYGON); //empezar partida
	glVertex3f(-10, 3.5,-1);
	glVertex3f(12, 3.5,-1);
	glVertex3f(12, -2.3,-1);
	glVertex3f(-10, -2.3,-1);
	glEnd();
	
	glBegin(GL_POLYGON); //salir del juego
	glVertex3f(-10, -5.2,-1);
	glVertex3f(12, -5.2,-1);
	glVertex3f(12, -11,-1);
	glVertex3f(-10, -11,-1);
	glEnd();
	
	}
	if (estado == modosJuego) {

		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/modos.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-28.0f, -20.0f, 0.0f);
		glTexCoord2d(1, 1); glVertex3f(28.0f, -20.0f, 0.0f);
		glTexCoord2d(1, 0); glVertex3f(28.0f, 20.0f, 0.0f);
		glTexCoord2d(0, 0); glVertex3f(-28.0f, 20.0f, 0.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

	}
} 

void Game::mousePress(int button, int state, int x, int y) {

	if (estado == inicioPartida)
	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 165 && x <= 835 && y >= 266 && y <= 480) {
				estado = modosJuego;
			}
			else if (x >= 165 && x <= 835 && y >= 101 && y <= 184) {
				exit(0);
			}

		}
	}
}

