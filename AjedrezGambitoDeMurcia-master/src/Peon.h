#pragma once
#pragma once
#include "freeglut.h"
#include "Vector2d.h"
#include "pieza.h"
#include "ETSIDI.h"
class Peon : public pieza
{
public:
	Peon();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	float getPosFila() {
		return Coord.getFila();
	}
	float getPosColumna() {
		return Coord.getColumna();
	}
	virtual bool desplazamientovalido(int fil, int col);
};

