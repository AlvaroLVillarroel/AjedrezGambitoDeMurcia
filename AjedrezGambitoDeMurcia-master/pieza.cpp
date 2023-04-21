#include "pieza.h"
#include "ETSIDI.h"

pieza::pieza(){
	Coord.setFila(1);
	Coord.setColumna(1);
}
pieza::~pieza()
{
}
pieza::pieza(paises pais, equipos equipo, tipoPieza pieza, Coordenadas coord)
{
	this->Pais = pais;
	this->Equipo = equipo;
	this->Pieza = pieza;
	this->Coord = coord;
}

int pieza::getFila()
{
	return Coord.getFila();
}

int pieza::getColumna()
{
	return Coord.getColumna();
}

void pieza::setFila(int row)
{
	Coord.setFila(row);
}

void pieza::setColumna(int column)
{
	Coord.setColumna(column);
}

void pieza::dibujarPieza()
{

	glColor3ub(240, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3d(-4.5 + Coord.getColumna() - 1, 4.5 - Coord.getFila() + 1, 1);
	glVertex3d(-4.5 + Coord.getColumna() - 1, 3.5 - Coord.getFila() + 1, 1);
	glVertex3d(-3.5 + Coord.getColumna() - 1, 3.5 - Coord.getFila() + 1, 1);
	glVertex3d(-3.5 + Coord.getColumna() - 1, 4.5 - Coord.getFila() + 1, 1);
	glEnd();
	glEnable(GL_LIGHTING);
};

void pieza::moverPieza()
{

}
