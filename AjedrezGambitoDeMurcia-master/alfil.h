#pragma once
#include"pieza.h"

class alfil
{
	paises pais;
	equipos equipo;
	tipoPieza pieza;
	Coordenadas Coord;

public:
	alfil(paises pais, equipos equipo, tipoPieza pieza, Coordenadas coord);
	void dibujarPieza();
	void moverPieza(float fil,float col);
};