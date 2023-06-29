#pragma once
#include"pieza.h"

class alfil : public pieza
{

public:
	alfil();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	virtual bool desplazamientovalido(int fil,int col);
};