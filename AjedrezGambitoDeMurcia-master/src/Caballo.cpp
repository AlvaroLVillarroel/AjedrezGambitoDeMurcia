#include "Caballo.h"

void Caballo::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	tp = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void Caballo::dibujarPieza() {
	//pieza::dibujarFondo();

	glEnable(GL_TEXTURE_2D);
	if (pais == SPAIN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/caballo.png").id);
	if (pais == ARGENTINA)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/caballos.png").id);
	if (pais == BRAZIL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/caballos.png").id);
	if (pais == JAPAN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/caballos.png").id);
	if (pais == PORTUGAL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/caballos.png").id);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0);
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



Caballo::Caballo() {
	pais = JAPAN;
	equipo = EQUIPO_A;
	tp = ALFIL;
}
bool Caballo::desplazamientovalido(int fil, int col) {
		if ((abs(getFila() - fil) == 2 && abs(getColumna() - col) == 1) || (abs(getFila() - fil) == 1 && abs(getColumna() - col) == 2))return true;
	return false;
}


