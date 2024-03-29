
#include "game.h"
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
//#include <Windows.h>



Game::Game()
{
	estado = inicioPartida;
	tablasJUG1 = false;
	tablasJUG2 = false;
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
	if (tablasJUG1) {

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/tick.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0);
		
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-5.3f, 2.8, 2.0f);
		glTexCoord2d(1, 1); glVertex3f(-4.6, 2.8, 2.0f);
		glTexCoord2d(1, 0); glVertex3f(-4.6, 3.8, 2.0f);
		glTexCoord2d(0, 0); glVertex3f(-5.3f, 3.8, 2.0f);
		glEnd();
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	

	}
	if (tablasJUG1) {

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/tick.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0);
		
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-5.3f, 2.8, 2.0f);
		glTexCoord2d(1, 1); glVertex3f(-4.6, 2.8, 2.0f);
		glTexCoord2d(1, 0); glVertex3f(-4.6, 3.8, 2.0f);
		glTexCoord2d(0, 0); glVertex3f(-5.3f, 3.8, 2.0f);
		glEnd();
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	if (tablasJUG2) {

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/tick2.png").id);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.0);
		
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(5.3f, 2.8, 2.0f);
		glTexCoord2d(1, 1); glVertex3f(4.6, 2.8, 2.0f);
		glTexCoord2d(1, 0); glVertex3f(4.6, 3.8, 2.0f);
		glTexCoord2d(0, 0); glVertex3f(5.3f, 3.8, 2.0f);
		glEnd();
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	if (estado == jugando) {

		tablero.dibujarTablero();
		tablero.dibujarJugadores();
		if (tablasJUG1 == true && tablasJUG2 == true)
			estado = tablas;

		tablero.dibujarPromocion();
		
	}
	
	if (estado == pausa) {

		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/pausa.png").id);
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
	if (estado == ganaJUG1) {
		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/ganaJUG1.png").id);
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
	if (estado == ganaJUG2) {
		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/ganaJUG2.png").id);
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
	if (estado == tablas) {
		tablasJUG1 = false;
		tablasJUG2 = false;
		gluLookAt(0, 0, 40,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

		//dibuja pantalla de inicio

		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/pantallaTablas.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex3f(-28.0f, -20.0f, 1.0f);
		glTexCoord2d(1, 1); glVertex3f(28.0f, -20.0f, 1.0f);
		glTexCoord2d(1, 0); glVertex3f(28.0f, 20.0f, 1.0f);
		glTexCoord2d(0, 0); glVertex3f(-28.0f, 20.0f, 1.0f);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
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

void Game::mousePress(int button, int state, int x, int y) {

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {

		if (x >= 30 && x <= 100 && y >= 0 && y <= 720 && estado!=jugando) {
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
				//DAMAS_LOCAS
				tablero.damaslocas = true;

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

	}
	if (estado == seleccionJUG2)
	{
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//Hay que ajustar valores acorde a las coord de los botones
			if (x >= 190 && x <= 345 && y >= 260 && y <= 430 && tablero.pa!=PORTUGAL) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = PORTUGAL;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
				empezar = true;
			}
			else if (x >= 420 && x <= 575 && y >= 260 && y <= 430 && tablero.pa != JAPAN) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = JAPAN;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
				empezar = true;
			}
			else if (x >= 650 && x <= 800 && y >= 260 && y <= 430 && tablero.pa != SPAIN) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = SPAIN;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
				empezar = true;
			}
			else if (x >= 320 && x <= 475 && y >= 450 && y <= 610 && tablero.pa != ARGENTINA) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = ARGENTINA;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
				empezar = true;
			}
			else if (x >= 540 && x <= 690 && y >= 450 && y <= 610 && tablero.pa != BRAZIL) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablero.pa1 = BRAZIL;
				estado = jugando;
				tablero.inicializa();
				ETSIDI::play("sonidos/select.wav");
				empezar = true;
			}
		}
	}
	if (estado == jugando) {
		
		if (empezar) {
			ETSIDI::play("sonidos/start.wav");
			empezar = false;
			
		}
		tablero.juega(button, state, x, y);
		if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		{
			//std::cout << x << " " << y;
			//rendirse
			if (x >= 15 && x <= 61 && y >= 85 && y <= 137) {
				x = 0;
				y = 0;
				estado = ganaJUG2;
				ETSIDI::play("sonidos/game-end.mp3");
				//ETSIDI::play("sonidos/select.wav");
			}
			//tablas
			if (x >= 73 && x <= 153 && y >= 93 && y <= 125) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablasJUG1 = true;
				ETSIDI::play("sonidos/select.wav");
			}
			//tablas
			if(x >= 842 && x <= 924 && y >= 93 && y <= 125) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				tablasJUG2 = true;
				ETSIDI::play("sonidos/select.wav");
			}
			//rendirse
			if(x >= 942 && x <= 986 && y >= 90 && y <= 136) {
				SetCursor(LoadCursor(NULL, IDC_HAND));
				x = 0;
				y = 0;
				estado=ganaJUG1;
				//ETSIDI::play("sonidos/select.wav");
				ETSIDI::play("sonidos/game-end.mp3");
			}
		}
	}
	if (estado == pausa) {

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
				estado = jugando;
				ETSIDI::play("sonidos/select.wav");
			}


		}

	}
	if (estado == ganaJUG1 || estado == ganaJUG2) {

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
				tablero.reiniciarTablero();
				ETSIDI::play("sonidos/select.wav");
				tablero.damaslocas = false;
				std::cout << "perdiste bro"<<std::endl;
			}


		}

	}
	if (estado == tablas)

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
				tablero.reiniciarTablero();
				estado = modosJuego;
				ETSIDI::play("sonidos/select.wav");
				tablero.damaslocas = false;
			}
		}
	}
	if (tablero.piezas.ganaJUG1) {
		tablero.reiniciarTablero();
		estado = ganaJUG1;
		tablero.piezas.ganaJUG1 = false;
	}
	if (tablero.piezas.ganaJUG2) {
		tablero.reiniciarTablero();
		estado = ganaJUG2;
		tablero.piezas.ganaJUG2 = false;
	}
	if (tablero.piezas.tablas) { 
		estado = tablas;
		tablero.piezas.tablas = false;
	}
}
void Game::music()
{
	if (musicPlaying && estado != jugando) {
		ETSIDI::stopMusica();
		musicPlaying = false;
	}
	else {
		if (estado != jugando) {
			ETSIDI::playMusica("sonidos/fondo.mp3", true);
			musicPlaying = true;
		}
	}

}

void Game::tecla(unsigned char key)
{
	if (estado == jugando && (key == 'p' || key == 'P')) {
		estado = pausa;
	}
}

