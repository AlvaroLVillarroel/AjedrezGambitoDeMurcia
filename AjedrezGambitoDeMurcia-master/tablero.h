#pragma once
#include <iostream>
#include "freeglut.h"
//#include "coordenadas.h"
#include "game.h"
#include "pieza.h"

class Tablero {
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
	void dibujarTablero();
	void resizeTablero(unsigned char key);
	void arrayCasillas(int c, int f);
	void dibujarCoordenadasx(int a);
	void dibujarCoordenadasy(int a);
};