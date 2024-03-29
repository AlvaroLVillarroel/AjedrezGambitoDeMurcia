#pragma once
#include "coordenadas.h"
#include <cmath>
#include "ETSIDI.h"
#include <string>
enum paises{SPAIN,JAPAN,BRAZIL,PORTUGAL,ARGENTINA};
enum equipos { EQUIPO_A, EQUIPO_B, SELECCION };
enum tipoPieza{PEON,ALFIL,TORRE,CABALLO,REINA,REY};

class pieza
{
protected:
	bool negra;
	paises pais;
	equipos equipo;
	tipoPieza tp;
	Coordenadas Coord;
	pieza(paises pais, equipos equipo, tipoPieza tipopieza, Coordenadas coord);
	int movimientos;
public:
	pieza();
	int getFila(); //obtiene valor de fila
	int getColumna(); //obtiene valor de columna
	void moverPieza(int fil, int col);
	void setFila(int row); //modifica valor de fila
	void setColumna(int column); //modifica valor de columna
	virtual void dibujarPieza(); //dibuja la pieza
	virtual bool desplazamientovalido(int fil,int col);
	std::string comprobarPieza();
	tipoPieza getpieza() { return tp; } //devuelve el tipo de pieza
	equipos getequipo() { return equipo; }
	paises getPais() { return pais; }
	int getmovimientos() { return movimientos; }
	void sumarmovimientos() { movimientos++; }
};
