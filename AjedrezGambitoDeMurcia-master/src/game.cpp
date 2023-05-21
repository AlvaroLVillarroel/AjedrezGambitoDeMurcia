
#include "game.h"
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include <Windows.h>

Game::Game()
{
	estado = inicioPartida;
	music();
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
	
	}
	if (estado == modosJuego) 
	{

		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/modos.png").id);
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
	if (estado == seleccionJUG1) {

		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/seleccionJUG1.png").id);
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
	if (estado == seleccionJUG2)
	{

		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/seleccionJUG2.png").id);
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
			if (x >= 310 && x <= 740 && y >= 450 && y <= 550) {
				exit(0);
			}
			if (x >= 310 && x <= 740 && y >= 300 && y <= 400) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				estado = seleccionJUG1;
			}
			
		}

		

	}
	if (estado == seleccionJUG1)
	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 190 && x <= 345 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == PORTUGAL
				estado = seleccionJUG2;
			}
			else if (x >= 420 && x <= 575 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == JAPON
				estado = seleccionJUG2;
			}
			else if (x >= 650 && x <= 800 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == SPAIN
				estado = seleccionJUG2;
			}
			else if (x >= 320 && x <= 475 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == ARGENTINA
				estado = seleccionJUG2;
			}
			else if (x >= 540 && x <= 690 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == BRAZIL
				estado = seleccionJUG2;
			}
		}

	}
	if (estado == seleccionJUG2)
	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 190 && x <= 345 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == PORTUGAL
				
			}
			else if (x >= 420 && x <= 575 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == JAPON
				
			}
			else if (x >= 650 && x <= 800 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == SPAIN
			
			}
			else if (x >= 320 && x <= 475 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == ARGENTINA
			
			}
			else if (x >= 540 && x <= 690 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				//equipo == BRAZIL
				
			}
		}

	}
}

void Game::music()
{
	if (modoMusica == true) {
		modoMusica = false;
		ETSIDI::stopMusica();
	}
	else if (modoMusica == false) {
		modoMusica = true;
		ETSIDI::playMusica("sonidos/fondo.mp3", true);
	}
	
}

