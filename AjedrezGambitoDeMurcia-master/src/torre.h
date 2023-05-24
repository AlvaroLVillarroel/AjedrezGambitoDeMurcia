#pragma once
#include "pieza.h"
class torre : public pieza
{

public:
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	float getPosFila() {
		return Coord.getFila();
	}
	float getPosColumna() {
		return Coord.getColumna();
	}
	bool desplazamientovalido(int fil, int col);
};

