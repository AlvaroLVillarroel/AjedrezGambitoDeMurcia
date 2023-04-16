
#pragma once
#include <iostream>
#include "freeglut.h"

enum Estado {inicio,modos,modo_pvp,modo_rapido,pausa};
class Game
{
public:
	void dibuja();
	void mousePress(int button, int state,int x,int y );
	void music();
	Estado estado;
}; 
