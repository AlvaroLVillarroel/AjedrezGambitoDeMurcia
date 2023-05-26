#include "rey.h"
#include "freeglut.h"
#include "ETSIDI.h"
void rey::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	tp = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void rey::dibujarPieza() {
	

	glEnable(GL_TEXTURE_2D);

	if (pais == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/reys.png").id);
	if (pais == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/reys.png").id);
	if (pais == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/reys.png").id);
	if (pais == PORTUGAL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/reys.png").id);
	if (pais == ARGENTINA) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/reys.png").id);


	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0);
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
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}
rey::rey() {
	pais = JAPAN;
	equipo = EQUIPO_A;
	tp = REY;
}
bool rey::desplazamientovalido(int fil, int col) {

	

	if (movimientos == 0) {
		if((abs(getFila()-fil)==0)&&(abs(getColumna()-col)==2))return true;
		if ((abs(getFila() - fil) <= 1) && (abs(getColumna() - col) <= 1))return true;
		return false;
	}
	else if (movimientos != 0) {
		if ((abs(getFila() - fil) == 0) && (abs(getColumna() - col) == 2))return false;
		if ((abs(getFila() - fil) <= 1) && (abs(getColumna() - col) <= 1))return true;
		return false;
	}

}