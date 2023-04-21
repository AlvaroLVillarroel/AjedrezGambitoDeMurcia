#include "alfil.h"

alfil::alfil(paises pais, equipos equipo, tipoPieza pieza, Coordenadas coord){
	this->pais = pais;
	this->equipo = equipo;
	this->pieza = pieza;
	this->Coord = coord;
}

void alfil::dibujarPieza() {
	glTranslated(Coord.getFila(), Coord.getColumna(), 0.0f);
	if (pais == 0) glColor3ub(255, 0, 0);
	if (pais == 1) glColor3ub(255, 255, 255);
	if (pais == 2) glColor3ub(60, 193, 15);
	if (pais == 3)glColor3ub(187, 35, 5);
	if (pais == 4)glColor3ub(20, 222, 182);
	glutSolidSphere(3.0f, 20, 20);
	glTranslated(-Coord.getFila(), -Coord.getColumna(), 0.0f);
}

void alfil::moverPieza(float fil, float col) {
	if (abs(Coord.getFila()-fil) == abs(Coord.getColumna()-col)) {
		Coord.setFila(fil);
		Coord.setColumna(col);
	}
}