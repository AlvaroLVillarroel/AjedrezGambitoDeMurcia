#pragma once
#include "pieza.h"
class torre : public pieza
{

public:
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	void moverPieza(float fil, float col);
	void sumar_movimiento();
};

