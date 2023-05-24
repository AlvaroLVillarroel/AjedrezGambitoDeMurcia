#pragma once
#include "ETSIDI.h"
#include "pieza.h"
#include "rey.h"
#include "dama.h"
#include "caballo.h"
#include "Alfil.h"
#include "Torre.h"
#include "Peon.h"
#include "coordenadas.h"
#define MAX_PIEZAS 100
class ListaPiezas:public pieza {
	pieza* lista[MAX_PIEZAS];
	int windowXPos = 0;
	int windowYPos = 0;
	int numero = 0;
	int casillax, casillay = 0;
public:
	ListaPiezas();
	bool agregar(pieza* p);
	void dibuja();
	void mueve(pieza* p,int fil, int col);
	void destruirPiezas();
	void eliminarPieza(int ref);
	void eliminarPieza(pieza* p);
	int getNumero() { return numero; }
	void lista_inicial(paises p1,paises p2);
	void agregarPeon(paises p,equipos e,int fil,int col);
	void agregarTorre(paises p, equipos e, int fil, int col);
	void agregarCaballo(paises p, equipos e, int fil, int col);
	void agregarAlfil(paises p, equipos e, int fil, int col);
	void agregarDama(paises p, equipos e, int fil, int col);
	void agregarRey(paises p, equipos e, int fil, int col);
	bool piezaencasilla(int fil, int col);
	bool colisionalfil(pieza* pi, int fil, int col);
	bool colisiontorre(pieza* pi, int fil, int col);
	bool colisionreina(pieza* pi, int fil, int col);
	bool colisionpeon(pieza* pi, int fil, int col);
	bool colisionpieza(pieza* pi, int fil, int col);
	void mousePress(int button, int state, int x, int y);
	pieza* piezaseleccionada(int fil, int col);
	
};