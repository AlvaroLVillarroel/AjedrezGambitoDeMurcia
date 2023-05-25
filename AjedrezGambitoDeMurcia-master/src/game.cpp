
#include "game.h"
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
//#include <Windows.h>



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

		if (musicPlaying)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/notmuted.png").id);
			glDisable(GL_LIGHTING);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.0);
			glTranslated(-22, -18, 0.0);
			glBegin(GL_POLYGON);
			glTexCoord2d(0, 1); glVertex3f(-3.5f, -1, 1.0f);
			glTexCoord2d(1, 1); glVertex3f(0, -1, 1.0f);
			glTexCoord2d(1, 0); glVertex3f(0, 3, 1.0f);
			glTexCoord2d(0, 0); glVertex3f(-3.5f, 3, 1.0f);
			glEnd();
			glDisable(GL_BLEND);
			glDisable(GL_ALPHA_TEST);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		else
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/muted.png").id);
			glDisable(GL_LIGHTING);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.0);
			glTranslated(-22, -18, 0.0);
			glBegin(GL_POLYGON);
			glTexCoord2d(0, 1); glVertex3f(-3.5f, -1, 1.0f);
			glTexCoord2d(1, 1); glVertex3f(0, -1, 1.0f);
			glTexCoord2d(1, 0); glVertex3f(0, 3, 1.0f);
			glTexCoord2d(0, 0); glVertex3f(-3.5f, 3, 1.0f);
			glEnd();
			glDisable(GL_BLEND);
			glDisable(GL_ALPHA_TEST);
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
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
	if (estado == jugando) {

		tablero.dibujarTablero();

	}
}

void Game::mousePress(int button, int state, int x, int y) {

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {

		if (x >= 30 && x <= 100 && y >= 0 && y <= 720 && estado == inicioPartida) { //cuando le estas y la musica esta on
			SetCursor(LoadCursor(NULL, IDC_HAND));
			x = 0;
			y = 0;
			music();
		}
	}

	if (estado == inicioPartida)

	{

		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 310 && x <= 740 && y >= 450 && y <= 550) {
				x = 0;
				y = 0;
				exit(0);
				ETSIDI::play("sonidos/select.wav");
			}
			if (x >= 310 && x <= 740 && y >= 300 && y <= 400) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				estado = modosJuego;
				ETSIDI::play("sonidos/select.wav");
			}


		}



	}
	if (estado == modosJuego)

	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 350 && x <= 490 && y >= 380 && y <= 500) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				estado = seleccionJUG1;
				ETSIDI::play("sonidos/select.wav");
				//pvp
			}
			if (x >= 580 && x <= 720 && y >= 380 && y <= 500) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				estado = seleccionJUG1;
				ETSIDI::play("sonidos/select.wav");
				//pve

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
				x = 0;
				y = 0;
				tablero.pa = PORTUGAL;
				estado = seleccionJUG2;
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 420 && x <= 575 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa = JAPAN;
				estado = seleccionJUG2;
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 650 && x <= 800 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa = SPAIN;
				estado = seleccionJUG2;
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 320 && x <= 475 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa = ARGENTINA;
				estado = seleccionJUG2;
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 540 && x <= 690 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa = BRAZIL;
				estado = seleccionJUG2;
				ETSIDI::play("sonidos/select.wav");
			}
		}
		std::cout << tablero.pa;

	}
	if (estado == seleccionJUG2)
	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 190 && x <= 345 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = PORTUGAL;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 420 && x <= 575 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = JAPAN;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 650 && x <= 800 && y >= 260 && y <= 430) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = SPAIN;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 320 && x <= 475 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = ARGENTINA;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
			}
			else if (x >= 540 && x <= 690 && y >= 450 && y <= 610) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = BRAZIL;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
			}
		}
		std::cout << tablero.pa1;
	}
	if (estado == jugando) {
		tablero.juega(button, state, x, y);
	}
}
void Game::music()
{
	if (musicPlaying) {
		ETSIDI::stopMusica();
		musicPlaying = false;
	}
	else {
		ETSIDI::playMusica("sonidos/fondo.mp3", true);
		musicPlaying = true;
	}

}

