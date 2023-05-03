#include "dama.h"
#include "freeglut.h"
#include "ETSIDI.h"
dama::dama() {
	pais = SPAIN;
	equipo = EQUIPO_A;
	pieza = ALFIL;

	movimientos = 0;
}
void dama::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	pieza = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void dama::dibujarPieza() {

	glEnable(GL_TEXTURE_2D);

	if (pais == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/reina.png").id);
	if (pais == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/reina.png").id);
	if (pais == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/reina.png").id);
	if (pais == PORTUGAL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/reina.png").id);
	if (pais == ARGENTINA) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/reina.png").id);


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

void dama::moverPieza(float fil, float col) {
	if (abs(Coord.getFila() - fil) == abs(Coord.getColumna() - col)) {
		Coord.setFila(fil);
		Coord.setColumna(col);
		sumar_movimiento();
	}
}

void dama::sumar_movimiento() {
	movimientos++;
}