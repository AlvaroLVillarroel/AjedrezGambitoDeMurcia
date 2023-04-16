#include "pieza.h"


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
	
	glTranslatef(Coord.getFila(),Coord.getColumna(), 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f); // color amarillo
	glutSolidSphere(0.5f, 20, 20); // esfera de radio 0.5
	
}
