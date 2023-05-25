#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "tablero.h"



enum Estado {inicioPartida,modosJuego,seleccionJUG1,seleccionJUG2,modo_pvp,modo_rapido,pausa,jugando};

class Game
{
public:
	Game();
	void dibuja();
	void mousePress(int button, int state,int x,int y );
	void music();
	bool musicPlaying=false;
	Estado estado;
	Tablero tablero;
private:
	
}; 
