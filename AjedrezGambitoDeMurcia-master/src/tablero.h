#pragma once
#include <iostream>
#include "freeglut.h"
//#include "coordenadas.h"
#include "game.h"
#include "pieza.h"
#include "ETSIDI.h"
#include "alfil.h"
#include "Caballo.h"
#include "dama.h"
#include "rey.h"

class Tablero {
	int posiciones[8][8];
	alfil f1c3;
	alfil f1c6;
	alfil f8c3;
	alfil f8c6;
	Caballo Cb8;
	Caballo Cg8;
	Caballo Cb1;
	Caballo Cg1;
	dama f1cd;
	dama f8cd;
	rey f1ce;
	rey f8ce;
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
	//void resizeTablero(unsigned char key);
	/*void arrayCasillas(int c, int f);
	void dibujarCoordenadasx(int a);
	void dibujarCoordenadasy(int a);
	*/
};