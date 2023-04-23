#pragma once
#include"pieza.h"

class alfil
{
	paises pais;
	equipos equipo;
	tipoPieza pieza;
	Coordenadas Coord;

	int movimientos = 0;

public:
	alfil(paises pais, equipos equipo, tipoPieza pieza, Coordenadas coord);
	void dibujarPieza();
	void moverPieza(float fil,float col);
	void sumar_movimiento();
};