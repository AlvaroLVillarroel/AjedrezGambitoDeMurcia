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
	glColor3f(1, 1, 1);
	if (pais == SPAIN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/spain/peon.png").id);
	if (pais == ARGENTINA)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/argentina/peon.png").id);
	if (pais == BRAZIL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/brazil/peon.png").id);
	if (pais == JAPAN)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/japan/peon.png").id);
	if (pais == PORTUGAL)glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/portugal/peon.png").id);
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

void Peon::moverPieza(float fil, float col) {
	Coord.setFila(fil);
	Coord.setColumna(col);
	sumar_movimiento();
}

void Peon::sumar_movimiento() {
	movimientos++;
}

Peon::Peon() {
	pais = JAPAN;
	equipo = EQUIPO_A;
	tp =PEON;
	mouseX = mouseY = 0;
	movimientos = 0;
}
void Peon::mousePress(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (x >= getPosFila() - 5 && x <= getPosColumna() - 4 &&
			y >= getPosFila() + 4 && y <= getPosFila() + 5) {
			isDragging = true;
			mouseX = x - getPosColumna();
			mouseY = y - getPosFila();
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		isDragging = false;
	}
}
void Peon::mouseMotion(float x, float y) {
	if (isDragging) {
		moverPieza(x - mouseX, y - mouseY);
		glutPostRedisplay(); // Redibujar la ventana
	}
}