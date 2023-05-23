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
	if (pais == ARGENTINA)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/caballo.png").id);
	if (pais == BRAZIL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/caballo.png").id);
	if (pais == JAPAN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/caballo.png").id);
	if (pais == PORTUGAL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/caballo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0); glVertex3f(-4.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(0, 1); glVertex3f(-4.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 1); glVertex3f(-3.0 + Coord.getColumna() - 1, 3.0 - Coord.getFila() + 1, 1.5);
	glTexCoord2d(1, 0); glVertex3f(-3.0 + Coord.getColumna() - 1, 4.0 - Coord.getFila() + 1, 1.5);
	glEnd();
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
	if ((abs(Coord.getFila() - 3 == 0 && abs(Coord.getColumna() - 1) == 0)) || (abs(Coord.getFila() - 1 == 0 && abs(Coord.getColumna() - 3) == 0)))return true;
	return false;

}


