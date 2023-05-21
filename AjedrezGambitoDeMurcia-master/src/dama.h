#pragma once
#include"pieza.h"
class dama: public pieza
{
	bool isDragging = false;
	float mouseX, mouseY;
	int movimientos;

public:
	dama();
	void inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col);
	void dibujarPieza();
	float getPosFila() {
		return Coord.getFila();
	}
	float getPosColumna() {
		return Coord.getColumna();
	}
	void mousePress(int button, int state, int x, int y);
	void mouseMotion(float x, float y);
	bool desplazamientovalido(int fil,int col);
};

