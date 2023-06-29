#include <iostream>
#include "freeglut.h"
#include "coordenadas.h"

Coordenadas::Coordenadas(int fila, int columna)
{
    this->fila = fila;
    this->columna = columna;
}

int Coordenadas::getFila()
{
    return fila;
}

int Coordenadas::getColumna()
{
    return columna;
}

void Coordenadas::setFila(int row)
{
    this->fila = row;
}

void Coordenadas::setColumna(int column)
{
    this->columna = column;
}

Vector2d Coordenadas::CoordtoVector()
{
    int x = getFila();
    int y = getColumna();
    return Vector2d(x,y);
}

