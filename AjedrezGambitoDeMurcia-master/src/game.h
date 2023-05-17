
#pragma once
#include <iostream>
#include "freeglut.h"
#include "ETSIDI.h"
enum Estado {inicioPartida,modosJuego,seleccionJUG1,seleccionJUG2,modo_pvp,modo_rapido,pausa,jugando};
class Game
{
public:
	Game();
	void dibuja();
	void mousePress(int button, int state,int x,int y );
	void music();
	Estado estado;
private:
	bool modoMusica = false;
}; 
