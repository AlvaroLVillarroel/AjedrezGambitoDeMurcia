#pragma once
#include"pieza.h"
class rey:public pieza
{
public:
	rey();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	virtual bool desplazamientovalido(int fil, int col);
};

