#pragma once
#include "ETSIDI.h"
#include "pieza.h"
#include "rey.h"
#include "dama.h"
#include "caballo.h"
#include "Alfil.h"
#include "Torre.h"
#include "Peon.h"
#include "pieza.h"
#define MAX_PIEZAS 100
class ListaPiezas {
	pieza* lista[MAX_PIEZAS];
	int numero = 0;
public:
	ListaPiezas();
	bool agregar(pieza* p);
	void dibuja();
	void mueve(int fil, int col);
	void destruirPiezas();
	void eliminarPieza(int ref);
	void eliminarPieza(pieza* p);
	int getNumero() { return numero; }
};