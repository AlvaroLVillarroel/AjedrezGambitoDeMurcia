#pragma once
#include <iostream>
#include "freeglut.h"
class Coordenadas{
public:
  float x[8][8], y[8][8];
    void setCord();
    void dibujarPrueba();
};