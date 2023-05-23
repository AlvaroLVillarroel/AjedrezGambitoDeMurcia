#pragma once
#include <iostream>
#include "freeglut.h"
//#include "coordenadas.h"
#include "game.h"
#include "ListaPIezas.h"
#include "ETSIDI.h"
#include "alfil.h"
#include "Caballo.h"
#include "dama.h"
#include "rey.h"

class Tablero {
	int posiciones[8][8];
	ListaPiezas piezas;
public:
	pieza prueba;
	GLfloat x1=0;
	GLfloat y1=0;
	GLfloat x2=8;
	GLfloat y2=8;
	int flagrz = 0;
	float a = 1.5;
	//Coordenadas cord;
	const unsigned char columnas[8] = { '1','2','3', '4', '5', '6', '7','8' };
	const unsigned char filas[8] = { 'a','b','c', 'd', 'e', 'f', 'g','h'};
	unsigned char tecla;
	void inicializa();
	void dibujarTablero();
	void juega(int button,int state,int x,int y);
};