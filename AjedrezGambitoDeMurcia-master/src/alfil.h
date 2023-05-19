#pragma once
#include"pieza.h"

class alfil : public pieza
{
	paises pais;
	equipos equipo;
	tipoPieza pieza;
	Coordenadas Coord;

	int movimientos;

public:
	alfil();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	void moverPieza(float fil,float col);
	void sumar_movimiento();
};