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
	pieza(paises pais, equipos equipo, tipoPieza pieza);
	void dibujarPieza();
};

