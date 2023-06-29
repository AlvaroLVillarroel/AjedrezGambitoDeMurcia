#pragma once
#include <iostream>
#include "freeglut.h"
#include "Vector2d.h"

enum color{NEGRO, BLANCO, NADA};
class Coordenadas{
    int fila;
    int columna;
public:
    Coordenadas() {}
    Coordenadas(int fila, int columna); //constructor
    int getFila(); //obtiene valor de fila
    int getColumna(); //obtiene valor de columna
    void setFila(int row); //modifica valor de fila
    void setColumna(int column); //modifica valor de columna
    Vector2d CoordtoVector();
};