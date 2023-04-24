
#pragma once
#include <iostream>
#include "freeglut.h"

enum Estado {inicioPartida,modosJuego,modo_pvp,modo_rapido,pausa,jugando};
class Game
{
public:
	Game();
	void dibuja();
	void mousePress(int button, int state,int x,int y );
	void music();
	Estado estado;
}; 
