#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "tablero.h"



enum Estado {inicioPartida,modosJuego,seleccionJUG1,seleccionJUG2,modo_DAMA_LOCA,pausa,jugando,ganaJUG1, ganaJUG2,tablas};

class Game
{
public:
	Game();
	
	void dibuja();
	void mousePress(int button, int state,int x,int y );
	void music();
	void tecla(unsigned char key);
	bool musicPlaying=false;
	bool empezar = true;
	Estado estado;
	Tablero tablero;
	bool tablasJUG1 = false;
	bool tablasJUG2=false;

}; 
