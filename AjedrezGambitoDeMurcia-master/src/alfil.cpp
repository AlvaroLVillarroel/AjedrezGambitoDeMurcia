#include "alfil.h"
#include "freeglut.h"
#include "ETSIDI.h"

void alfil::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	pieza = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void alfil::dibujarPieza() {

	glEnable(GL_TEXTURE_2D);

	if (pais == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/alfil.png").id);
	if (pais == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/alfil.png").id);
	if (pais == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/alfil.png").id);
	if (pais == PORTUGAL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/alfil.png").id);
	if (pais == ARGENTINA)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/alfil.png").id);


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glTexCoord2d(0, 0);
	glVertex3d(-4.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(0, 1);
	glVertex3d(-4.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 1);
	glVertex3d(-3.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 0);
	glVertex3d(-3.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
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