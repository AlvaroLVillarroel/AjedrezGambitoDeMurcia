#include "alfil.h"
#include "freeglut.h"

void alfil::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	pieza = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void alfil::dibujarPieza() {
	if (pais == SPAIN) glColor3ub(255, 0, 0);
	if (pais == JAPAN) glColor3ub(255, 255, 255);
	if (pais == BRAZIL) glColor3ub(60, 193, 15);
	if (pais == PORTUGAL)glColor3ub(187, 35, 5);
	if (pais == ARGENTINA)glColor3ub(20, 222, 182);

	
	glBegin(GL_POLYGON);
	glVertex3d(-4.5 + Coord.getColumna() - 1, 4.5 - Coord.getFila() + 1, 1.5);
	glVertex3d(-4.5 + Coord.getColumna() - 1, 3.5 - Coord.getFila() + 1, 1.5);
	glVertex3d(-3.5 + Coord.getColumna() - 1, 3.5 - Coord.getFila() + 1, 1.5);
	glVertex3d(-3.5 + Coord.getColumna() - 1, 4.5 - Coord.getFila() + 1, 1.5);
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

alfil::alfil() {
	pais = SPAIN;
	equipo = EQUIPO_A;
	pieza = ALFIL;

	movimientos = 0;
}