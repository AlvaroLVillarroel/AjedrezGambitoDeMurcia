#include "Peon.h"
void Peon::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	tp = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void Peon::dibujarPieza() {
	//pieza::dibujarFondo();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0);
	if (pais == SPAIN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/peons.png").id);
	if (pais == ARGENTINA)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/peons.png").id);
	if (pais == BRAZIL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/peons.png").id);
	if (pais == JAPAN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/peons.png").id);
	if (pais == PORTUGAL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/peons.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0); glVertex3f(-4.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(0, 1); glVertex3f(-4.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 1); glVertex3f(-3.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 0); glVertex3f(-3.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

}


Peon::Peon() {
	pais = JAPAN;
	equipo = EQUIPO_A;
	tp =PEON;
	movimientos = 0;
}

bool Peon::desplazamientovalido(int fil, int col) {
	if (equipo == EQUIPO_A) {
		if ((fil - getFila() == 1) && (col == getColumna()))return true;
		if ((fil - getFila() == 1) && (col - getColumna() == 1))return true;
		if ((fil - getFila() == 1) && (col - getColumna() == -1))return true;
	}
	if (equipo == EQUIPO_B) {
		if ((getFila()- fil == 1) && (col == getColumna()))return true;
		if ((getFila() - fil == 1) && (getColumna() - col == 1))return true;
		if ((getFila() - fil == 1) && (getColumna() - col == -1))return true;
	}
	if (movimientos == 0) {
		if (equipo == EQUIPO_A) {
			if ((fil - getFila() == 2) && (col == getColumna()))return true;
		}
		if (equipo == EQUIPO_B) {
			if ((getFila() - fil == 2) && (col == getColumna()))return true;
		}
	}
	return false;
}