#pragma once
#include"pieza.h"
class rey:public pieza
{
	int movimientos;

public:
	rey();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	bool desplazamientovalido(int fil, int col);
};

