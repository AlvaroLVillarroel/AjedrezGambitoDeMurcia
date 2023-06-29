#pragma once
#include "ETSIDI.h"
#include "pieza.h"
#include "rey.h"
#include "dama.h"
#include "caballo.h"
#include "Alfil.h"
#include "torre.h"
#include "Peon.h"
#include "coordenadas.h"
#include "player.h"


#define MAX_PIEZAS 100

class Game;
class ListaPiezas:public pieza {
	enum Seleccion { COORD_DEST, COORD_INI };
	enum promo { pDAMA, pTORRE, pCABALLO, pALFIL}; 
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
	//Tags para el enroque
	bool Torre_A_Izq;
	bool Torre_A_Drh;
	bool Torre_B_Izq;
	bool Torre_B_Drh;
	bool Enroque_rey_A;
	bool Enroque_rey_B;

	bool selecciona, seleccionb;
	promo promo;
public:
	int fila, colu;
	bool click1 = false;
	bool click2 = false;
	bool click12 = false;
	bool click22 = false;
	bool ganaJUG1 = false;
	bool ganaJUG2 = false;
	bool tablas = false;
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
	void comer(int fil,int col);
	bool jaque(equipos equipo);
	bool jaqueposible(pieza* pi, int fil, int col);
	bool JaqueMate(equipos equipo);
	bool comprobarPromocion(pieza* pi, int fil, int col);
	void promocion();
	equipos getTurno() { return turno; }
	bool getPromo() { return promocionflag; }
	void setTurno(equipos eq) { turno = eq; }
	void setPromo(bool flag) { promocionflag = flag; }
	void dibujarmovimientosposibles(pieza* pi);
	void dibujarmovpos(pieza* pi, int fil, int col);
	void dibujarmovs();
	void anularenroque(pieza* pi, int fil, int col);
	void dibujarPuntito();
	void seleccionPromocion(int button, int state, int x, int y);
	void damasLocas(paises p1, paises p2);
};