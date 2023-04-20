#pragma once
#include "coordenadas.h"
enum paises{SPAIN,JAPAN,BRAZIL,PORTUGAL,ARGENTINA};
enum equipos{EQUIPO_A,EQUIPO_B};
enum tipoPieza{PEON,ALFIL,TORRE,CABALLO,REINA,REY};

class pieza
{
	paises Pais;
	equipos Equipo;
	tipoPieza Pieza;
	Coordenadas Coord;

public:
	pieza(paises pais, equipos equipo, tipoPieza tipopieza, Coordenadas coord);
	pieza();
	~pieza();
	int getFila(); //obtiene valor de fila
	int getColumna(); //obtiene valor de columna
	void setFila(int row); //modifica valor de fila
	void setColumna(int column); //modifica valor de columna
	void dibujarPieza(); //dibuja la pieza
	void moverPieza();
};

