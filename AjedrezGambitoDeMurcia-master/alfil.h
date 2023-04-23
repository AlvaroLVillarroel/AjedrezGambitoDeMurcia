#pragma once
#include"pieza.h"

class alfil
{
	paises pais;
	equipos equipo;
	tipoPieza pieza;
	Coordenadas Coord;

	int movimientos;

public:
	alfil(paises pa, equipos eq, tipoPieza pi, int fil, int col) :pais(pa), equipo(eq), pieza(pi), Coord(fil, col) { movimientos = 0; }
	void dibujarPieza();
	void moverPieza(float fil,float col);
	void sumar_movimiento();
};