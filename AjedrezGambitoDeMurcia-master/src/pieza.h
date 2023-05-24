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
protected:
	bool negra;
	Game game;
	paises pais;
	equipos equipo;
	tipoPieza tp;
	Coordenadas Coord;
	pieza(paises pais, equipos equipo, tipoPieza tipopieza, Coordenadas coord);
	int movimientos;
public:
	pieza();
	~pieza();
	int getFila(); //obtiene valor de fila
	int getColumna(); //obtiene valor de columna
	void moverPieza(int fil, int col);
	virtual void setFila(int row); //modifica valor de fila
	virtual void setColumna(int column); //modifica valor de columna
	virtual void dibujarPieza(); //dibuja la pieza
	virtual void colorCasilla();
	virtual bool desplazamientovalido(int fil,int col);
	tipoPieza getpieza() { return tp; } //devuelve el tipo de pieza
	equipos getequipo() { return equipo; }
	int getmovimientos() { return movimientos; }

};
