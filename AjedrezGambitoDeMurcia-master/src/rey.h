#pragma once
#include"pieza.h"
class rey
{
	paises pais;
	equipos equipo;
	tipoPieza pieza;
	Coordenadas Coord;
	int movimientos;

public:
	rey();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	void moverPieza(float fil, float col);
	void sumar_movimiento();
};

