#pragma once
#include"pieza.h"

class alfil : public pieza
{
	int movimientos;

public:
	alfil();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	void moverPieza(float fil,float col);
	void sumar_movimiento();
	bool desplazamientovalido(int fil,int col);
};