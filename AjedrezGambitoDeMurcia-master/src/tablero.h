#pragma once
#include <iostream>
#include "freeglut.h"
//#include "coordenadas.h"
#include "ListaPiezas.h"
#include "ETSIDI.h"
#include "player.h"

class Tablero {
	int posiciones[8][8];
	
	player jugador1;
	player jugador2;
public:
	ListaPiezas piezas;
	paises pa,pa1;
	pieza prueba;
	GLfloat x1=0;
	GLfloat y1=0;
	GLfloat x2=8;
	GLfloat y2=8;
	bool damaslocas;
	int flagrz = 0;
	float a = 1.5;
	//Coordenadas cord;
	const unsigned char columnas[8] = { '1','2','3', '4', '5', '6', '7','8' };
	const unsigned char filas[8] = { 'a','b','c', 'd', 'e', 'f', 'g','h'};
	unsigned char tecla;
	void inicializa();
	void dibujarTablero();
	void dibujarJugadores();
	//void finalPartida();
	void juega(int button,int state,int x,int y);
	void mueve();
	void dibujarPromocion();
	void reiniciarTablero();
};