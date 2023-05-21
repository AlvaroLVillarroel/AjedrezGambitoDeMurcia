#pragma once
#pragma once
#include "freeglut.h"
#include "Vector2d.h"
#include "pieza.h"
#include "ETSIDI.h"
class Peon : public pieza
{
	bool isDragging = false;
	float mouseX, mouseY;
	int movimientos;

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
	bool desplazamientovalido(int fil, int col);
};

