#include "alfil.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "coordenadas.h"

void alfil::inicializa(paises pa, equipos eq, tipoPieza pi, int fil, int col) {
	pais = pa;
	equipo = eq;
	tp = pi;
	Coord.setFila(fil);
	Coord.setColumna(col);
}
void alfil::dibujarPieza() {
		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		if (pais == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/alfils.png").id);
		if (pais == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/alfil.png").id);
		if (pais == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/alfil.png").id);
		if (pais == PORTUGAL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/alfil.png").id);
		if (pais == ARGENTINA)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/alfil.png").id);

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
		glEnable(GL_TEXTURE_2D);	
}

bool alfil::desplazamientovalido(int fil, int col) {
	if (abs(Coord.getFila() - fil) == abs(Coord.getColumna() - col))return true;
	if ((getFila() == fil) && (getColumna() == col))return false;
	return false;
}


alfil::alfil() {
	pais = SPAIN;
	equipo = EQUIPO_A;
	tp = ALFIL;

	movimientos = 0;
}