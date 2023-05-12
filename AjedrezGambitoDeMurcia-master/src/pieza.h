#pragma once
#include "coordenadas.h"
#include <cmath>
#include "game.h"
#include "ETSIDI.h"
enum paises{SPAIN,JAPAN,BRAZIL,PORTUGAL,ARGENTINA};
enum equipos{EQUIPO_A,EQUIPO_B};
enum tipoPieza{PEON,ALFIL,TORRE,CABALLO,REINA,REY};

class pieza
{
public:
	Game game;
	paises pais;
	equipos equipo;
	tipoPieza tp;
	Coordenadas Coord;
	pieza(paises pais, equipos equipo, tipoPieza tipopieza, Coordenadas coord);
	pieza();
	~pieza();
	int getFila(); //obtiene valor de fila
	int getColumna(); //obtiene valor de columna
	void setFila(int row); //modifica valor de fila
	void setColumna(int column); //modifica valor de columna
	void dibujarPieza(); //dibuja la pieza
};

