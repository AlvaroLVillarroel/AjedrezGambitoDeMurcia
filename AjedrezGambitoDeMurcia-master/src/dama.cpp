#include "dama.h"
#include "freeglut.h"
#include "ETSIDI.h"
dama::dama() {
	pais = SPAIN;
	equipo = EQUIPO_A;
	tp = REINA;
}
void dama::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	tp = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void dama::dibujarPieza() {

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0);
	if (pais == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/reinas.png").id);
	if (pais == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/reinas.png").id);
	if (pais == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/reinas.png").id);
	if (pais == PORTUGAL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/reinas.png").id);
	if (pais == ARGENTINA) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/reinas.png").id);


	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0);
	glTexCoord2d(0, 0);
	glVertex3d(-4.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(0, 1);
	glVertex3d(-4.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 1);
	glVertex3d(-3.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 0);
	glVertex3d(-3.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);

	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool dama::desplazamientovalido(int fil, int col) {
	if (abs(getFila() - fil) == abs(getColumna() - col))return true;
	if ((getFila() == fil) && (getColumna() == col))return false;
	if ((getFila() == fil) || (getColumna() == col))return true;
	return false;
}