#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
#include "tablero.h"
#include "player.h"



enum Estado {inicioPartida,modosJuego,seleccionJUG1,seleccionJUG2,modo_pvp,modo_rapido,pausa,jugando,ganaJUG1, ganaJUG2};

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
	player jugador1;
	player jugador2;
private:
	
}; 
