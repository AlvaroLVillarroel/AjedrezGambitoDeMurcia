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
#include "player.h"

#define MAX_PIEZAS 100
class ListaPiezas:public pieza {
	enum Seleccion { COORD_DEST, COORD_INI };
	pieza* lista[MAX_PIEZAS];
	pieza* piezasel = 0;
	int windowXPos = 0;
	int windowYPos = 0;
	int numero = 0;
	bool piezaComida;
	int casillax, casillay;
	int casillax1, casillay1;
	Seleccion seleccion;
	//player jugador;
	equipos turno;
	Coordenadas vector[20];
	bool aux=false;
	bool promocionflag;
	bool promocioncheck;
	bool wait;
public:
	int fila, colu;
	bool click1 = false;
	bool click2 = false;
	bool click12 = false;
	bool click22 = false;
	ListaPiezas();
	//~ListaPiezas();
	bool agregar(pieza* p);
	void dibuja();
	void mueve(pieza* p,int fil, int col);
	void destruirPiezas(pieza* p, int fil, int col);
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
	bool colisionrey(pieza* pi, int fil, int col);
	bool colisionpieza(pieza* pi, int fil, int col);
	void mousePress(int button, int state, int x, int y);
	pieza* piezaseleccionada(int fil, int col);
	void MoverPieza();
	bool turnocorrecto(pieza* pi);
	bool movimientovalido(pieza* pi, int fil, int col);
	void moverPieza(pieza* pi, int fil, int col);

	void dibujarbalon(int fil, int col);
	bool enroquevalido(pieza* pi, int fil, int col);
	void hacerenroque(pieza* pi, int fil, int col);
	//void jaque(equipos equipo);
	void comer(pieza* pi, int fil,int col);
	//bool jaqueMate(equipos equipo);
	bool jaque(equipos equipo);
	bool jaqueposible(pieza* pi, int fil, int col);
	bool JaqueMate(equipos equipo);
	bool promocion(pieza* pi, int fil, int col);
	void dibujarPromocion();
	equipos getTurno() { return turno; }
	bool getPromo() { return promocionflag; }
	void setPromo(bool flag) { promocionflag = flag; }
	void esperar();
	void dibujarmovimientosposibles(pieza* pi);
	void dibujarmovpos(pieza* pi, int fil, int col);
	void dibujarmovs();
};