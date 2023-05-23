#pragma once
#include "freeglut.h"
#include "Vector2d.h"
#include "pieza.h"
#include "ETSIDI.h"
class Caballo: public pieza
{
public:
	Caballo();
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

