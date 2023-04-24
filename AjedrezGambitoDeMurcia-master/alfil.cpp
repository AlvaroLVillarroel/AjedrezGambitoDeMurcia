#include "alfil.h"

void alfil::dibujarPieza() {
	if (pais == 0) glColor3ub(255, 0, 0);
	if (pais == 1) glColor3ub(255, 255, 255);
	if (pais == 2) glColor3ub(60, 193, 15);
	if (pais == 3)glColor3ub(187, 35, 5);
	if (pais == 4)glColor3ub(20, 222, 182);
	/*
	glTranslated(Coord.getFila(), Coord.getColumna(), 0.0f);
	glutSolidSphere(3.0f, 20, 20); 
	glTranslated(-Coord.getFila(), -Coord.getColumna(), 0.0f);
	*/
	glBegin(GL_POLYGON);
	glVertex3d(-5.5 + Coord.getColumna(), 5.5 - Coord.getFila(), 1);
	glVertex3d(-5.5 + Coord.getColumna(), 4.5 - Coord.getFila(), 1);
	glVertex3d(-4.5 + Coord.getColumna(), 4.5 - Coord.getFila(), 1);
	glVertex3d(-4.5 + Coord.getColumna(), 5.5 - Coord.getFila(), 1);
	glEnd();
	glEnable(GL_LIGHTING);
}

void alfil::moverPieza(float fil, float col) {
	if (abs(Coord.getFila()-fil) == abs(Coord.getColumna()-col)) {
		Coord.setFila(fil);
		Coord.setColumna(col);
		sumar_movimiento();
	}
}

void alfil::sumar_movimiento() {
	movimientos++;
}